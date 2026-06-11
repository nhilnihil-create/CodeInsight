#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fcout cout << fixed << setprecision(18)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  double n, m, d;
  cin >> n >> m >> d;
  double ans = 2 * (n - d) * (m - 1.0) / n / n;
  if (d == 0) ans /= 2;
  fcout << ans << '\n';
  return 0;
}