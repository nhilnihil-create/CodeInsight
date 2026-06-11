#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> x(m), diff(m);
  diff[0] = (int)1e6;
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  for (int i = 1; i < m; i++) {
    diff[i] = abs(x[i] - x[i - 1]);
  }
  sort(diff.begin(), diff.end());
  int ans = 0;
  if (n >= m) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < m - n; i++) {
    ans += diff[i];
  }
  cout << ans << '\n';
  return 0;
}
