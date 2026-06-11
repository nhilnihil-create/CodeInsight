#include <bits/stdc++.h>
#define inf (long long)(1e18)
using namespace std;

long long n, a, b;
vector<int> p;
vector<vector<long long>> dp;

long long solve();

int main() {
  cin >> n >> a >> b;
  p.resize(n);
  for (auto &x : p) cin >> x;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = inf;
  dp.assign(n + 1, vector<long long>(n + 1, inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= n; ++j)
      if (p[i] < j)
        dp[i + 1][j] = dp[i][j] + b;
      else if (p[i] > j)
        dp[i + 1][j] = dp[i][j] + a;
      else
        for (int k = 0; k < j; ++k) dp[i + 1][j] = min(dp[i + 1][j], dp[i][k]);
  for (int i = 0; i <= n; ++i) res = min(res, dp[n][i]);
  return res;
}