#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);
int n;
int arr[100000][3];
int point[100000][3];

int p(int row,int col)
{

    if(row == n-1)
    {
        return arr[n-1][col];
    }
    if(point[row][col]>0)
    {
        return point[row][col];
    }

    else if(col==0)
    {
        return point[row][col]=arr[row][col]+max(p(row+1,1),p(row+1,2));
    }

    else if(col==1)
    {
        return point[row][col]=arr[row][col]+max(p(row+1,0),p(row+1,2));
    }
    else if(col==2)
    {
        return point[row][col]=arr[row][col]+max(p(row+1,0),p(row+1,1));
    }

}




int main()
{
    optimize();

    cin>>n;



    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>arr[i][j];
        }
    }

    int res=max(p(0,0),max(p(0,1),p(0,2)));
    cout<<res;

}

