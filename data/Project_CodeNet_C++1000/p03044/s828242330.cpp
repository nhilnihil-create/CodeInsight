#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

void dfs(ll cur, ll par,ll par_color,vector<vector<pair<ll,ll>>> &adj,vector<ll> &ans){
  for(auto v:adj[cur]){
  	if(v.first==par && v.second==0)
      ans[cur] = par_color;
    else if(v.first==par && v.second==1)
      ans[cur] = (par_color+1)%2;
  }
  for(auto v:adj[cur]){
  	if(v.first==par)
      continue;
    dfs(v.first,cur,ans[cur],adj,ans);
  }
}

int main(){
  ll n;
  cin>>n;
  vector<vector<pair<ll,ll>>> adj(n+1);
  for(ll i=1;i<=n;i++){
     ll t1,t2,t3;
     cin>>t1>>t2>>t3;
     adj[t1].push_back({t2,t3%2});
     adj[t2].push_back({t1,t3%2});
  }
  vector<ll> ans(n+1);
  dfs(1,0,0,adj,ans);
  for(ll i=1;i<=n;i++)
    cout<<ans[i]<<endl;
}