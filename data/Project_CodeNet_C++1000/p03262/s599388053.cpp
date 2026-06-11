#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i] - x);
  }
  int ans = a[0];
  for (int i = 1; i < n; i++) {
    ans = gcd(ans, a[i]);
  }
  cout << ans << '\n';
  return 0;
}