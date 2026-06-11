#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1, n);
  dp[0] = 0;
  vector<int> c = {1};
  for (int d = 6; d <= n; d *= 6) c.push_back(d);
  for (int d = 9; d <= n; d *= 9) c.push_back(d);
  for (int d : c) {
    for (int i = 0; i <= n - d; i++) {
      dp[i + d] = min(dp[i + d], dp[i] + 1);
    }
  }
  cout << dp[n] << '\n';
}