#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll mod = 1e9 + 7;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

using Edge = pair<int, ll>;
using Graphy = vector<vector<Edge> >;

int n;
Graphy g;
vector<int> ans(n);

void dfs(int v, int p, int c) {
  ans[v] = c;
  for (auto e : g[v]) {
    if (e.first == p) continue;
    if (e.second & 1) dfs(e.first, v, 1-c);
    else dfs(e.first, v, c);
  }
}

int main() {
  cin >> n;
  g.assign(n, vector<Edge>());
  rep(i,n-1) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back(Edge(v,w));
    g[v].push_back(Edge(u,w));
  }
  ans.assign(n,0);
  dfs(0, -1, 0);

  for (auto d : ans) cout << d << endl;

  return 0;
}
