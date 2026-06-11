#include <bits/stdc++.h>
using namespace std;
inline void chmin (long long& a, long long b) {
  if (a > b) a = b;
}
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> p(n + 2);
  p[0] = 0;
  p[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  vector<long long> dp(n + 2, 1e18);
  dp[0] = 0;
  for (int i = 1; i <= n + 1; i++) {
    long long tmp = 0;
    for (int j = i - 1; j >= 0; j--) {
      if (p[j] < p[i]) {
        chmin(dp[i], dp[j] + tmp);
        tmp += b;
      } else {
        tmp += a;
      }
    }
  }
  cout << dp[n + 1] << '\n';
  return 0;
}
