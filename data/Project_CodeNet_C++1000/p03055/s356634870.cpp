#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 5;

int diam = 0;
vector<int> adj[MXN];
int dp[MXN];

int dfs(int x, int p) {
  int mx1 = 0;
  int mx2 = 0;
  for (int y : adj[x]) {
    if (y == p) continue;
    int res = dfs(y, x);
    if (res > mx1) swap(res, mx1);
    if (res > mx2) swap(res, mx2);
  }
  diam = max(diam, mx1 + 1 + mx2);
  return mx1 + 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  dp[1] = 1;
  dp[3] = 1;
  dp[4] = 1;
  for (int i = 5; i < MXN; ++i) {
    dp[i] = (dp[i - 2] & dp[i - 3]) | (dp[i - 3] & dp[i - 4]);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1, 0);
  cout << (dp[diam]? "First" : "Second") << '\n';
}
