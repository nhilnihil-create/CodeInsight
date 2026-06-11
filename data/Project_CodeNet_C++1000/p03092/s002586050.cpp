#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5005;
int dp[N][N], p[N], cnt[N][N], a, b, n;

int solve(int i, int j) {
  if (i == 0 || j == 0) {
    return 0;
  }
  if (~dp[i][j]) {
    return dp[i][j];
  }
  if (p[i - 1] >= j) {
    return solve(i - 1, j);
  }
  int cur = cnt[i][j] - cnt[i][p[i - 1] + 1];
  return dp[i][j] = min(solve(i - 1, j) + b, solve(i - 1, min(p[i - 1], j)) + cur * a);
}

signed main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < N; j++) {
      cnt[i + 1][j] = cnt[i][j] + (p[i] < j);
    }
  }
  cout << solve(n, n) << '\n';
  return 0;
}

