#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  ll m = min({a, b, c, d, e});
  ll cnt = (n - 1) / m + 1;
  ll ans = 5 + cnt - 1;
  cout << ans << endl;
  return 0;
}
