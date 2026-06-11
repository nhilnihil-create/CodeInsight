#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void addEdge(vector<ll> adj[], ll u, ll v){
  adj[u].push_back(v);
}

void dfs(vector<ll> adj[], ll node, bool vis[], ll dp[]){
  vis[node]=true;
  for(ll i=0; i<adj[node].size(); i++){
    if(!vis[adj[node][i]]){
      dfs(adj,adj[node][i], vis, dp);
    }
    dp[node] = max(dp[node], 1+dp[adj[node][i]]);
  }
}

ll longestPath(vector<ll> adj[], ll n){
  ll dp[n+1];
  memset(dp, 0, sizeof(dp));
  bool vis[n+1];
  memset(vis, false, sizeof(vis));
  for(ll i=1; i<=n; i++){
    if(!vis[i]){
      dfs(adj,i,vis,dp);
    }
  }
  ll ans=0;
  for(ll i=0; i<=n; i++){
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main(){
  ll n,m;
  cin>>n>>m;
  vector<ll> adj[n+1];
  while(m--){
    ll u,v;
    cin>>u>>v;
    addEdge(adj,u,v);
  }
  ll ans = longestPath(adj, n);
  cout<<ans<<"\n";
  
  return 0;
}
