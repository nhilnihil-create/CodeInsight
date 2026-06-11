#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
pair<long long, long long> fnc (int l, int r) {
  long long sum = a[r] - a[l];
  int i = lower_bound(a.begin() + l, a.begin() + r, a[l] + ((sum + 1) >> 1)) - a.begin();
  long long maxv = min(a[i] - a[l], sum - a[i - 1] + a[l]);
  long long minv = sum - maxv;
  return {maxv, minv};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  long long minv = 9e18;
  for (int q = 2; q <= n - 2; q++) {
    auto x = fnc(0, q);
    auto y = fnc(q, n);
    minv = min(minv, max(x.first, y.first) - min(x.second, y.second));
  }
  cout << minv << '\n';
  return 0;
}