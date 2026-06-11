#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
double calc(long long x) {
  int sum = 0;
  long long xx = x;
  while (xx) {
    sum += xx % 10;
    xx /= 10;
  }
  return 1. * x / sum;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  vector<long long> a;
  for (int i = 1; i <= 9999; i++) {
    for (long long j = i; j <= 1e16; j = j * 10 + 9) {
      a.push_back(j);
    }
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  int n = (int) a.size();
  vector<double> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = calc(a[i]);
  }
  for (int i = n - 2; i >= 0; i--) {
    b[i] = min(b[i + 1], b[i]);
  }
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    if (abs(calc(a[i]) - b[i]) <= 1e-10) ans.push_back(a[i]);
  }
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}