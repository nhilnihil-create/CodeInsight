#include<bits/stdc++.h>
#define ll long long
#define gcd(x,y) __gcd(x,y)
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
const ll MOD = (1e9)+7;
const ll mod = 998244353;
const ll inf=(1LL<<62);
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline A abs(A &a) { return (a < 0 ? -a : a); }
using namespace std;
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r, g, b, n, ans = 0;
  cin >> r >> g >> b >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      ll a = r * i + g * j;
      if (n - a >= 0) {
        if ((n - a) % b == 0) {
        ans++;
       }
      }
    }
  }

  cout << ans << "\n";
  return (0);
}
