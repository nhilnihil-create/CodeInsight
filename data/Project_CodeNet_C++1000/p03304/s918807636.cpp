#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m, d;
  cin >> n >> m >> d;

  double ans;
  if (d == 0) {
    ans = 1.0 / (double)n;
  }
  else {
    ans = (double)(2 * n - 2 * d) / (double)(n * n);
  }

  ans *= (double)(m - 1);
  cout << fixed << setprecision(15);
  cout << ans << endl;
  return 0;
}