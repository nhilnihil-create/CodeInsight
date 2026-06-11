#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int dp[2][100001];
long long int mod=1e9+7;
long long int dfs(int node,int parent,int color,vector<int > Tree[])
{
    if(Tree[node].size()==1&&node!=1)
    {
        return 1; 
    }
    if(dp[color-1][node]!=-1)
    return dp[color-1][node];
    int i;
    long long int ans=1;
    for(i=0;i<Tree[node].size();i++)
    {
        if(Tree[node][i]!=parent)
        {
            if(color==1)
            ans*=dfs(Tree[node][i],node,2,Tree);
            else 
            ans*=dfs(Tree[node][i],node,2,Tree)+dfs(Tree[node][i],node,1,Tree);
        }
        ans%=mod;
    }
    return dp[color-1][node]=ans%mod;
}

int main()
{
  int n;
  cin>>n;
  vector<int > Tree[n+1];
  int i,x,y;
  memset(dp,-1,sizeof(dp));
  for(i=0;i<n-1;i++)
  {
    cin>>x>>y;
    Tree[x].push_back(y);
    Tree[y].push_back(x);
  }
long long int  ans=dfs(1,1,2,Tree)+dfs(1,1,1,Tree);
  //vector<bool> visited(n+1,false);
  cout<<ans%mod<<endl;
    return 0;
}