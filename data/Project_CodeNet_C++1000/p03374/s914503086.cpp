#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  long long n, c;
  cin >> n >> c;
  vector<long long> v(n + 2), x(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i];
  }
  x[1 + n] = c;
  long long cur = 0;
  vector<long long> dp1(n + 2);
  for (int i = 1; i <= n; i++) {
    cur += v[i];
    cur -= x[i] - x[i - 1];
    dp1[i] = max(dp1[i - 1], cur);
  }
  cur = 0;
  vector<long long> dp2(n + 2);
  for (int i = n; i >= 0; i--) {
    cur += v[i];
    cur -= x[i + 1] - x[i];
    dp2[i] = max(dp2[i + 1], cur);
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max({ans, dp1[i] + dp2[i + 1] - x[i], dp1[i] + dp2[i + 1] + x[i + 1] - c});
  }
  cout << ans << endl;
  return 0;
}