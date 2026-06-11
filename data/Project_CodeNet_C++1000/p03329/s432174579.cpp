#include <bits/stdc++.h>
#define ll long long
const ll inf=(1LL<<62);
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline A abs(A &a) { return (a < 0 ? -a : a); }
using namespace std;
signed main() {
  ll n;
  cin >> n;
  ll ans = n;
  for (int i = 0; i <= n; i++) {
    ll a = 0;
    ll t = i;
    while (t > 0) {
      a += t % 6;
      t /= 6;
    }
    t = n - i;
    while (t > 0) {
      a += t % 9;
      t /= 9;
    }
    if (ans > a) {
      ans = a;
    }
  }
  cout << ans << "\n";

  return(0);
}
