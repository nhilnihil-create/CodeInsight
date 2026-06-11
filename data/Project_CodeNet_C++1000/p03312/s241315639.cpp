#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> sum(n + 1);
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }
  long long ans = 1LL << 60;
  int j = 2, k = 4;
  for (int i = 3; i <= n - 1; i++) {
    long long x = abs(sum[j - 1] - (sum[i - 1] - sum[j - 1]));
    for (; j + 1 < i && x >= abs(sum[j] - (sum[i - 1] - sum[j])); j++) x = abs(sum[j] - (sum[i - 1] - sum[j]));
    long long y = abs(sum[k - 1] - sum[i - 1] - (sum[n] - sum[k - 1]));
    for (; k < n && y >= abs(sum[k] - sum[i - 1] - (sum[n] - sum[k])); k++) y = abs(sum[k] - sum[i - 1] - (sum[n] - sum[k]));
    long long mx = 0;
    long long mi = 1LL << 60;
    long long s1 = sum[j - 1];
    long long s2 = sum[i - 1] - sum[j - 1];
    long long s3 = sum[k - 1] - sum[i - 1];
    long long s4 = sum[n] - sum[k - 1];
    mx = max({s1, s2, s3, s4});
    mi = min({s1, s2, s3, s4});
    ans = min(ans, abs(mx - mi));
  }
  cout << ans << '\n';
  return 0;
}