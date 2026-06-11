#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (a[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1] + 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  long long ans = 0;
  int cur = -100;
  for (int i = n - 1; i >= 0; i--) {
    cur--;
    if (cur < a[i]) {
      ans += a[i];
      cur = a[i];
    }
  }
  cout << ans << endl;
  return 0;
}