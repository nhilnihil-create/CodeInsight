#include <bits/stdc++.h> 
#define ll long long 
const int N = 5000001; 
using namespace std; 
int n,m;
int solve(int row,int column,vector<vector<char> > &v,vector<vector<int> > &dp)
{
    int count=0;
    if((row>=n)||(column>=m))
    return 0;
    if((row==n-1)&&(column==m-1))
    return 1;
    if(v[row][column]=='#')
    return 0;
    if(dp[row][column]!=-1)
        return dp[row][column];
        
        count=(solve(row+1,column,v,dp)%(int)(1e9+7))+(solve(row,column+1,v,dp)%(int)(1e9+7));
    return dp[row][column]=(count%(int)(1e9+7));
}
int main()
{
    cin>>n>>m;
    vector<vector<char> > v( n , vector<char> (m));
    vector<vector<int> > dp( n , vector<int> (m,-1));
    char x;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            v[i][j]=x;
        }
    }
    int row=0;int column=0;
    cout<<solve(row,column,v,dp);
}
