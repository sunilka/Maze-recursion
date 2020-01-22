// implement the maze problem
#include<bits/stdc++.h>
using namespace std;

int ans[10][10];

void intializeans(int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            ans[i][j] = 1;
        }
    }
}

void print(int ans[10][10],int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    exit(0);
}

void maze(int a[10][10],int row,int col,int i,int j)
{
    if(i==row-1 && j == col-1) //means that i have reached my target
    {
        ans[i][j] = 9;
        print(ans,row,col);
        return;
    }

    else if(i<0 || j>col-1)
    {
        return;
    }

    else if(ans[i][j] == 9)
    {
        return;
    }

    else
    {
        if(a[i][j] == 0)
        {
            ans[i][j] = 9;
            maze(a,row,col,i,j+1); //east
            maze(a,row,col,i,j-1); //west
            maze(a,row,col,i-1,j); //north
            maze(a,row,col,i+1,j); //south
            maze(a,row,col,i-1,j+1);//north east
            maze(a,row,col,i+1,j-1); //south west
            maze(a,row,col,i-1,j-1); //north west
            maze(a,row,col,i+1,j+1); //south east
            ans[i][j] = 1;
        }

    }
}

int main()
{
    int row,col;
    cout<<"Please enter the no of rows and col in the matrix :";
    cin>>row>>col;

    int a[10][10];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>a[i][j];
        }
    }

    intializeans(row,col);
    maze(a,row,col,0,0);
}
