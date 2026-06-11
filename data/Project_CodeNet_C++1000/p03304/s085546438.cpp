#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, m, d;
  cin >> n >> m >> d;

  double x = (d == 0) ? n : 2 * (n - d);
  double ans = x * (m - 1) / (1.0 * n * n);
  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}
