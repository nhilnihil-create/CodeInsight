#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ga(n);
  vector<vector<int>> gb(n);
  string col;
  cin >> col;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (col[a] == col[b]) {
      ga[a].push_back(b);
      ga[b].push_back(a);
    } else {
      gb[a].push_back(b);
      gb[b].push_back(a);
    }
  }
  vector<vector<int>> g(n);
  vector<pair<int, int>> ed;
  for (int i = 0; i < n; i++) {
    for (int x : ga[i]) {
      for (int y : gb[i]) {
        g[x].push_back(y);
        ed.emplace_back(x, y);
      }
    }
  }
  vector<int> ord;
  vector<int> id(n);
  vector<bool> mark(n);
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
  for (int i = 0; i < n; i++) {
    if (!mark[i]) {
      Dfs(i);
    }
  }
  bool found = false;
  for (auto e : ed) {
    found |= (id[e.second] > id[e.first]);
  }
  cout << (found ? "Yes" : "No") << '\n';
  return 0;
}
