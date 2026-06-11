#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;

void dfs(int curr, vector<int> adj[], vector<int> &dp, vector<bool> &vis){
    vis[curr] = true;
    for(int i = 0; i < adj[curr].size();i++){
        if(!vis[adj[curr][i]])
            dfs(adj[curr][i], adj, dp, vis);
            
        dp[curr] = max(dp[curr], 1+dp[adj[curr][i]] );
    }
    return;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    return;
}

int solution(){
    int n,m; cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0;i < m;i++){
        int u,v; cin>>u>>v;
        addEdge(adj, u , v);
    }
    
    vector<bool> vis(n+1, false);
    vector<int> dp(n+1, 0);
    for(int i = 1;i <= n;i++){
        if(!vis[i])
            dfs(i, adj, dp, vis);
    }
    
    int ans = INT_MIN;
    for(int i = 1;i <= n;i++)
        ans = max(ans, dp[i]);
    
    cout<<ans<<"\n";
    return 0;
}

int main(){
    FAST_IO;
    int T = 1; //cin>>T;
    while(T--)
        solution();
    return 0;
}