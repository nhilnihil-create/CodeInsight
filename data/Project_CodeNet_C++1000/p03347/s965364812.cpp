#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0 && a[0] != 0) {
      cout << -1 << '\n';
      return 0;
    }
  }
  int cur = 0;
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] < cur) {
      cout << -1 << '\n';
      return 0;
    } else if (a[i] > cur) {
      cur = a[i];
      ans += cur;
    }
    if (cur) --cur;
  }
  cout << (cur ? -1 : ans) << '\n';
  return 0;
}
