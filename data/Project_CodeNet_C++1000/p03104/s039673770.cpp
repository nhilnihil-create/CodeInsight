#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

// ll h(int A, int x) { return A / x; }

// ll g(int A, int B, int x) {
//   int d = h(B, x) - h(A - 1, x);
//   if (d % 2 == 0) return 0;
//   return x;
// }

ll g(ll x, int i) {
  ll d = pow(2, i + 1);
  ll a = x % d;
  ll b = x / d;
  return b * (d / 2) + max(0LL, a - (d / 2 - 1));
}

ll h(ll x, ll y, int i) {
  ll c = g(y, i) - g(x, i);
  if (c & 1) return pow(2, i);
  return 0;
}

int main() {
  ll a, b;
  cin >> a >> b;

  ll ans = 0;
  rep(i, 45) { ans += h(a - 1, b, i); }
  cout << ans << endl;
  return 0;
}
