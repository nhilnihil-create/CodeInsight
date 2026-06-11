#include <bits/stdc++.h>

using namespace std;

const int N = 2000 * 2000 + 5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  vector<bitset<N>> dp(2);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    dp[(i + 1) & 1] = dp[i & 1] | (dp[i & 1] << a[i]);
  }
  for (int i = (sum + 1) / 2; i <= sum; i++) {
    if (dp[n & 1][i]) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}