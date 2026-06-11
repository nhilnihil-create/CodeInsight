#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> dp;
int ans = INT_MIN;

int dfs(int v) {
  if (dp[v] != -1) {
    return dp[v];
  }
  int path = 0;
  for (auto c : g[v]) {
    path = max(path, 1 + dfs(c));
  }
  ans = max(ans, path);
  dp[v] = path;
  return path;
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  dp.assign(n, -1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
  }
  for (int i = 0; i < n; ++i) {
    if (dp[i] == -1) {
      dfs(i);
    }
  }
  cout << ans << '\n';
  return 0;
}

