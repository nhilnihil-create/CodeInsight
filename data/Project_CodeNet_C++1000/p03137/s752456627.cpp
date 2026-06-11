#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  int x[m];
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }

  if (n >= m) {
    // 最初からすべてのMiにコマを配置する。
    cout << 0 << endl;
    return 0;
  }

  sort(x, x + m);
  ll dif[m - 1];
  for (int i = 0; i < m - 1; i++) {
    dif[i] = (x[i + 1] - x[i]);
  }
  sort(dif, dif + (m - 1), greater<ll>());

  ll ans = x[m - 1] - x[0];
  // 長い区間を除外していく
  for (int i = 0; i < n - 1; i++) {
    ans -= dif[i];
  }

  cout << ans << endl;
  return 0;
}