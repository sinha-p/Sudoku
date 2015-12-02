#include<iostream>
#include<stdio.h>
using namespace std;
const int N=9;

bool findblankaddr(int grid[N][N],int &row,int &col)
{
    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
            if(grid[row][col]==0)
                return true;
    }
    return false;
}
bool inrow(int grid[N][N],int row,int n)
{
    for(int c=0;c<N;c++)
        if(grid[row][c]==n)
            return true;
    return false;
}
bool incol(int grid[N][N],int col,int n)
{
    for(int r=0;r<N;r++)
    {
        if(grid[r][col]==n)
            return true;
    }
    return false;
}
bool insubgrid(int grid[N][N],int r,int c,int n)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grid[i+r][j+c]==n)
                return true;
        }
    }
    return false;
}
bool check(int grid[N][N],int r,int c,int n)
{
    bool rowres,colres,subres;
    rowres=inrow(grid,r,n);
    colres=incol(grid,c,n);
    subres=insubgrid(grid,r-r%3,c-c%3,n);
    return (!rowres&&!colres&&!subres);
}
int printgrid(int grid[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}
bool solvesud(int grid[N][N])
{
    int row,col,num;
    if(!findblankaddr(grid,row,col))
        return true;
    for(num=1;num<=9;num++)
    {
        if(check(grid,row,col,num))
           {
               grid[row][col]=num;
               if(solvesud(grid))
                {return true;
                }
               grid[row][col]=0;
           }
    }
   return false;
}

int main()
{
    int grid[N][N]={0};
    int row,col,num;
    cout<<"==============================SUDOKU=========================================\n";
    cout<<"Enter 0 for blank spaces\n";
    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
        {
            scanf("%d",&grid[row][col]);
        }
    }
    printf("\nSOLUTION\n\n");
    bool res=solvesud(grid);
    if(res==true)
        printgrid(grid);
    else
        printf("No solution");
}

