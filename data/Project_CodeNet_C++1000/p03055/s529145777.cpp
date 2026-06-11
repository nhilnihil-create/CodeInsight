#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

struct edge{ int to, cost; };
pair< int, int > dfs(const vector<vector<edge>> &g, int idx, int par) {
  pair< int, int > ret(0, idx);
  for(auto &e : g[idx]) {
    if(e.to == par) continue;
    auto cost = dfs(g, e.to, idx);
    cost.first += e.cost;
    ret = max(ret, cost);
  }
  return ret;
}

int tree_diameter(const vector<vector<edge>> &g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return (q.first);
}


signed main(){

  int n; cin >> n;
  vector<vector<edge>> G(n);
  for(int i = 0; i < n-1; i++){
    int s,t; cin >> s >> t;
    s--, t--;
    G[s].push_back({t,1});
    G[t].push_back({s,1});
  }

  int res = tree_diameter(G);
  if(res % 3 != 1){
    cout << "First" << endl;
  }else{
    cout << "Second" << endl;
  }

  return 0;
}
