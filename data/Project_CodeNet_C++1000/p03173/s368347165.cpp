#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MAX));
  vector<ll> prefix(n);
  prefix[0] = a[0];
  for (int i = 1; i < n; ++i) {
    prefix[i] = prefix[i-1] + a[i];
  }
  for (int l = n-1; l >= 0; --l) {
    dp[l][l] = 0;
    for (int r = l + 1; r < n; ++r) {
      for (int i = l; i < r; ++i) {
        dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r] + prefix[r] - (l > 0 ? prefix[l-1]: 0));
      }
    }
  }
  cout << dp[0][n-1] << '\n';

  return 0;
}
