#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

vector<int> color;
vector<vector<pair<int, int>>> g;

void dfs(int v, int p, int c) {
  color[v] = c;
  for (auto a : g[v]) {
    if (a.first == p) continue;
    if (a.second % 2 == 0) dfs(a.first, v, c);
    else dfs(a.first, v, 1 - c);
  }
}

int main() {
  int n;
  cin >> n;
  g.assign(n, vector<pair<int, int>>());
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  color.assign(n, 0);
  dfs(0, -1, 0);
  rep(i, n) cout << color[i] << endl;
  return 0;
}
