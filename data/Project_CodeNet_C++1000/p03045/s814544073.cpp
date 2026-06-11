#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using graph = map<int,vector<int>>;

int dfs(graph &G, vector<bool> &seen, int v) {
  if (seen[v]) return 0;
  seen[v] = true;
  for (auto nv : G[v]) {
    if (seen[nv]) continue;
    dfs(G,seen,nv);
  }
  return 0;
}

int main() {
  int n,m;
  cin >> n >> m;
  graph G;
  rep(i,0,m) {
    int x,y,z;
    cin >> x >> y >> z;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  vector<bool> seen(n+1,false);
  int ans = 0;
  rep(v,1,n+1) {
    if (seen[v]) continue;
    ans++;
    dfs(G,seen,v);
  }
  cout << ans << endl;
  return 0;
}
