#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;

void dfs(int u, vector<vector<int>>& adjList, bool* vis, ll* dp){
    if(vis[u]){
        return;
    }
    
    if(adjList[u].empty()){
        dp[u] = 0;
        vis[u] = true;
        return;
    }
    
    int m = 0;
    for(int i=0; i<adjList[u].size(); i++){
        int v = adjList[u][i];
        dfs(v, adjList, vis, dp);
        m = (dp[v]>m)?dp[v]:m;
    }
    dp[u] = 1 + m;
    vis[u] = true;
    
}
 
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjList(n);
    
    while(m--){
        int u, v;
        cin>>u>>v;
        adjList[u-1].push_back(v-1);
    }
    bool vis[n];
    ll dp[n];
    memset(vis, false, sizeof(vis));
    memset(dp, false, sizeof(dp));
    
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, adjList, vis, dp);
        }
    }
    cout<<*max_element(dp, dp+n);
}