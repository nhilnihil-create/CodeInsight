#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;

int dfs(int p) {
  if (dp[p] != -1) return dp[p];
  dp[p] = 0;
  for (auto to: adj[p]) {
    dp[p] = max(dp[p], dfs(to) + 1);
  }
  return dp[p];
}

int main() {

  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
  }

  dp = vector<int>(n + 1, -1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i] == -1) {
      ans = max(ans, dfs(i));
    }
  }
  cout << ans << '\n';

  return 0;
}
