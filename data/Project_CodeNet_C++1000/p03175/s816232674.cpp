#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9+7;
#define pb push_back
typedef long long ll;
const long long int N = 1e5;

void dfs(int u,int parent,vector<vector<int>>& adj, vector<vector<ll>>& dp){
    for(auto it:adj[u]){
        if(it==parent) continue;
        dfs(it,u,adj,dp);
        dp[u][1] = (dp[u][1]*dp[it][0])%MOD;
        dp[u][0] = (dp[u][0]*((dp[it][0]+dp[it][1])%MOD))%MOD;
    }
    return;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+5);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<ll>> dp(n+5,vector<ll>(2,1));
    dfs(1,-1,adj,dp);
    cout<<(dp[1][0]+dp[1][1])%MOD;
    return 0;
}