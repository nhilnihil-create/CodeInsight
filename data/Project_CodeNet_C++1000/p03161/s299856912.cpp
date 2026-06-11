#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> costs(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    costs[i] = x;
  }
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i + j < n) {
        int cost = dp[i] + abs(costs[i] - costs[i + j]);
        dp[i + j] = min(dp[i + j], cost);
      }
    }
  }
  cout << dp[dp.size() - 1] << endl;
}
