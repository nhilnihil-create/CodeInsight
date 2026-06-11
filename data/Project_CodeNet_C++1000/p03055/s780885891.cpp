#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> dist(n);
  function<void(int, int)> Dfs = [&](int u, int p) {
    for (int v : g[u]) {
      if (v != p) {
        dist[v] = dist[u] + 1;
        Dfs(v, u);
      }
    }
  };
  dist[0] = 0;
  Dfs(0, -1);
  int u = max_element(dist.begin(), dist.end()) - dist.begin();
  dist[u] = 0;
  Dfs(u, -1);
  int d = *max_element(dist.begin(), dist.end());
  cout << (d % 3 == 1 ? "Second" : "First") << '\n';
  return 0;
}
