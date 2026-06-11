#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> dp(k + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (int j = 1; j <= k; ++j) dp[j] = (dp[j] + dp[j-1]) % M;
    vector<int> tmp(k + 1, 0);
    for (int j = 0; j <= k; ++j) {
      int l = j - x;;
      tmp[j]  = dp[j];
      if (l > 0) tmp[j] = (tmp[j] - dp[l-1] + M) % M;
    }
    swap(tmp, dp);
  }
  cout << dp[k] << '\n';
}
