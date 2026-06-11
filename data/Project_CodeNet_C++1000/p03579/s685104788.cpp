#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[100005];
int col[100005];
bool dfs(int cur, int c) {
  col[cur] = 1 - c;
  bool ok = true;
  for (int &nbr : g[cur]) {
    if (col[nbr] < 0) ok &= dfs(nbr, 1 - c);
    if (col[nbr] == col[cur]) return false;
  }
  return ok;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(col, -1, sizeof(col));
  bool bi = dfs(0, 0);
  if (!bi) {
    cout << 1LL * n * (n - 1) / 2 - m << endl;
  } else {
    int res[2] = {};
    for (int i = 0; i < n; i++) {
      res[col[i]]++;
    }
    cout << 1LL * res[0] * res[1] - m << endl;
  }
  return 0;
}