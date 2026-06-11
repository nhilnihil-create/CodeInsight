#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], int dp[], bool vis[]) 
{ 
    vis[node] = true; 
    for (int i = 0; i < adj[node].size(); i++) { 
  
        if (!vis[adj[node][i]]) 
            dfs(adj[node][i], adj, dp, vis); 
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]); 
    } 
} 
  
int main() {
    int m,n;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
    }
    int dp[n + 1]; 
    memset(dp, 0, sizeof dp); 
    bool vis[n + 1]; 
    memset(vis, false, sizeof vis); 
    for (int i = 1; i <= n; i++) { 
        if (!vis[i]) 
            dfs(i, adj, dp, vis); 
    } 
    int ans = 0; 
    for (int i = 1; i <= n; i++) { 
        ans = max(ans, dp[i]); 
    } 
    cout<<ans;
    return 0;
}