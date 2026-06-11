#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
// #define mp make_pair
#define S second
#define F first
// ll mod=1e9+7 ;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define input_from_file  freopen("input.txt", "r", stdin);
using namespace std::chrono; 
ll n,m,ans=0;vector<vector<ll>> vec;
vector<ll> vis,dist;
void dfs(ll i,ll par){
  if(vis[i]) return;
  vis[i]=1;
  for(auto x:vec[i]){
    if(x!=par){
      dfs(x,i);
      dist[i]=max(dist[i],dist[x]+1);
    }
  }
}
int main(){                fastIO
  // input_from_file
  cin>>n>>m;vec.resize(n+1);vis.resize(n+1,0);dist.resize(n+1,0);
  for(int i=0;i<m;i++){ll u,v;
    cin>>u>>v;vec[u].pb(v);
  }
  for(int i=1;i<=n;i++){
    if(!vis[i]) dfs(i,-1);
  }
  for(int i=1;i<=n;i++) ans=max(ans,dist[i]);
  // for(int i=1;i<=n;i++) cout<<dist[i]<<" ";cout<<endl;
  cout<<ans;
  return 0;
}