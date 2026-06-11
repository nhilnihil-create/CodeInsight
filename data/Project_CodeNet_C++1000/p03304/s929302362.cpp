#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  double n, m, d;
  cin >> n >> m >> d;
  
  double ans;
  ans = 2 * (n - d) * (m - 1) / pow(n, 2);
  if (d == 0) ans /= 2;
  
  cout << fixed << setprecision(10) << ans << '\n';
}