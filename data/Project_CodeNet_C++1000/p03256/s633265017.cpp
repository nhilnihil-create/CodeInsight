#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string col;
  cin >> col;
  string foo = "AABB";
  vector<vector<int>> g(4 * n);
  vector<pair<int, int>> ed;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    for (int it : {0, 1}) {
      for (int x = 0; x < 4; x++) {
        int y = (x + 1) % 4;
        if (col[a] != foo[x] || col[b] != foo[y]) continue;
        g[4 * a + x].push_back(4 * b + y);
        ed.emplace_back(4 * a + x, 4 * b + y);
      }
      swap(a, b);
    }
  }
  vector<int> ord;
  vector<int> id(4 * n);
  vector<bool> mark(4 * n);
  function<void(int)> Dfs = [&](int v) {
    mark[v] = 1;
    for (int to : g[v]) {
      if (!mark[to]) {
        Dfs(to);
      }
    }
    id[v] = (int) ord.size();
    ord.push_back(v);
  };
  for (int i = 0; i < 4 * n; i++) {
    if (!mark[i]) {
      Dfs(i);
    }
  }
  bool found = false;
  for (auto e : ed) {
    found |= (id[e.first] < id[e.second]);
  }
  cout << (found ? "Yes" : "No") << '\n';
  return 0;
}
