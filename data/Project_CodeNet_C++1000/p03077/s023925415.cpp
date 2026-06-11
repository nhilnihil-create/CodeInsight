#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;

  ll p = min(a, b);
  p = min(p, c);
  p = min(p, d);
  p = min(p, e);

  ll ans = (n + p - 1) / p + 4;

  cout << ans << endl;
}
