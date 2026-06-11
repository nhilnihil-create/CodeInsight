#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&g,vector<bool>&visited,vector<int>&dp,int i)
{
    visited[i]=true;
    for(auto edge:g[i])
    {
        if(!visited[edge])
            dfs(g,visited,dp,edge);
        dp[i]=max(dp[i],dp[edge]+1);
    }
}
int main() {
    int m,n;
    cin>>n>>m;
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++)
    {
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
    }
    vector<int>dp(n+1,0);
    vector<bool>visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            dfs(g,visited,dp,i);
    }
    int ans = 0; 
    for (int i = 1; i <= n; i++) { 
        ans = max(ans, dp[i]); 
    } 
    cout<<ans;
    return 0;
}
