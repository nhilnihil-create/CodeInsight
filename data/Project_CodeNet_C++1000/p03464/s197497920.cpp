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
  }
  if (a[n - 1] != 2) {
    cout << -1 << '\n';
    return 0;
  }
  vector<long long> mn(n + 1, 2), mx(n + 1, 2);
  for (int i = n - 1; i >= 0; i--) {
    mn[i] = mn[i + 1];
    mx[i] = mx[i + 1] + a[i] - 1;
    if (i > 0) {
      mn[i] += a[i - 1] - 1;
      mn[i] /= a[i - 1];
      mn[i] *= a[i - 1];
      mx[i] /= a[i - 1];
      mx[i] *= a[i - 1];
    }
    if (mn[i] > mx[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << mn[0] << " " << mx[0] << '\n';
  return 0;
}
