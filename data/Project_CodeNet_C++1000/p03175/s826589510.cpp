#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
vector<vector<int>> adj;
pair<ll,ll> dfs(int node,int pere){
  ll black = 1,white = 1;
  for(int i : adj[node]){
    if(i == pere) continue;
    ll black_i,white_i;
    tie(black_i,white_i) = dfs(i,node);
    black = (black*white_i)%mod;
    white = (white*(black_i+white_i))%mod;
  }
  return {black,white};
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,u,v;
  cin >> n;
  adj.resize(n+1);
  for(int i = 1; i < n; ++i){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto pr = dfs(1,-1);
  cout << (pr.first+pr.second)%mod;
  return 0;
}