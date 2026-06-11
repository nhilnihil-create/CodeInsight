#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(int v, Graph& g, vector<bool>& visited, set<int>& path) {
  visited[v] = true;
  path.insert(v);
  for (int nv : g[v]) {
    if (!visited[nv]) {
      dfs(nv, g, visited, path);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i] -= 1;
  }

  Graph g(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int ans = 0;
  vector<bool> visited(n);
  for (int i = 0; i < n; ++i) {
    if (visited[i]) {
      continue;
    }
    set<int> path;
    dfs(i, g, visited, path);
    for (int x : path) {
      if (path.find(p[x]) != path.end()) {
        ans += 1;
      }
    }
  }
  cout << ans << endl;
}