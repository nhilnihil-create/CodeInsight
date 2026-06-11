#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> C(N);
  vector<vector<int>> pos(200010);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    pos[C[i]].emplace_back(i);
  }
  vector<int64_t> dp(200010, 0);
  dp[0] = 1;
  for (int i = 1; i < N + 1; i++) {
    dp[i] += dp[i - 1];
    dp[i] %= MOD;
    int p = lower_bound(pos[C[i - 1]].begin(), pos[C[i - 1]].end(), i - 1) - pos[C[i - 1]].begin();
    if (p > 0) {
      int j = pos[C[i - 1]][p - 1];
      if ((i - 1) - j > 1) {
        dp[i] += dp[j + 1];
        dp[i] %= MOD;
      }
    }
  }
  cout << dp[N] << '\n';
  return 0;
}
