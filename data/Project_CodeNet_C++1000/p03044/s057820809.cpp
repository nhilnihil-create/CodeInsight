#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

vector<int> color;

void dfs(vector<vector<pair<int, int>>> &g, int v, int c = 0) {
  color[v] = c;
  for (auto a : g[v]) {
    if (color[a.first] != -1) {
      continue;
    }
    if (a.second % 2 == 0) dfs(g, a.first, c);
    else dfs(g, a.first, 1 - c);
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  rep(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }
  color.assign(n, -1);
  rep(i, n) {
    if (color[i] != -1) continue;
    dfs(g, i);
  }
  rep(i, n) cout << color[i] << endl;
  return 0;
}
