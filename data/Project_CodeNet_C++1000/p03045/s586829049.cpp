#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll ans=0;
void dfs(ll cur,vector<vector<ll>> &adj,vector<ll> &vis){
  vis[cur]=1;
  for(auto v:adj[cur])
    if(!vis[v])
      dfs(v,adj,vis);
}

int main(){
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> adj(n+1);
  for(ll i=1;i<=m;i++){
     ll t1,t2,t3;
     cin>>t1>>t2>>t3;
     adj[t1].push_back(t2);
     adj[t2].push_back(t1);
  }
  vector<ll> vis(n+1);
  for(ll i=1;i<=n;i++)
    if(!vis[i]){
      ans++;
      dfs(i,adj,vis);
    }
  cout<<ans<<endl;
}