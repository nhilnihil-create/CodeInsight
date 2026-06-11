#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

signed main(){

  int n, m; cin >> n >> m;
  vector<int> a(m), b(m);
  vector<vector<int>> G(n);
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }

  vector<int> color(n, -1);
  function< void(int,int,int) > dfs =
  [&](int u, int pre, int t){
    color[u] = t^1;
    for(int v : G[u]){
      if(v == pre) continue;
      if(color[v] == -1) dfs(v, u, t^1);
      else if(color[v] != t){
        cout << n*(n-1)/2 - m << endl;
        exit(0);
      }
    }
    return;
  };
  dfs(0, -1, 0);

  int left = 0, right = 0;
  for(int i = 0; i < n; i++){
    if(color[i] == 0) left++;
    else right++;
  }
  cout << left * right - m << endl;

  return 0;
}
