// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
// }}}
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5;
int n;
int a[N];
const int mod = 1e9 + 7;

// WARN : use H with larger N
/// --- Modulo Factorial {{{ ///
template < int N, int mod = (int) 1e9 + 7 >
struct Factorial {
  constexpr ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = 0;
    return b == 0 ? (x = 1, y = 0, a)
      : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
  }
  constexpr ll modinv(ll a) {
    ll x = 0, y = 0;
    extgcd(a, mod, x, y);
    return (x + mod) % mod;
  }
  int arr[N + 1], inv[N + 1];
  ll operator[](int i) const { return arr[i]; }
#if !defined(DEBUG)
  constexpr
#endif
    Factorial()
    : arr(), inv() {
      arr[0] = 1;
      for(int i = 1; i <= N; i++) {
        arr[i] = (ll) i * arr[i - 1] % mod;
      }
      inv[N] = modinv(arr[N]);
      for(int i = N - 1; i >= 0; i--) {
        inv[i] = (ll)(i + 1) * inv[i + 1] % mod;
      }
    }
  ll C(int n, int r) const {
    if(n < 0 || r < 0 || n < r) return 0;
    return (ll) arr[n] * inv[r] % mod * inv[n - r] % mod;
  }
  ll H(int n, int r) const { return C(n + r - 1, r); }
};
/// }}}--- ///

Factorial < N, mod > fact;

/// --- math {{{ ///
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll extgcd(ll a, ll b, ll &x, ll &y) {
  ll d;
  return b == 0 ? (x = 1, y = 0, a)
    : (d = extgcd(b, a % b, y, x), y -= a / b * x, d);
}
ll modinv(ll a, ll mod = (ll) 1e9 + 7) {
  ll x, y;
  extgcd(a, mod, x, y);
  if(x < 0) x += mod;
  return x;
}
ll modpow(ll a, ll b, ll mod = (ll) 1e9 + 7) {
  ll r = 1;
  a %= mod;
  while(b) {
    if(b & 1) r = r * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return r;
}
/// }}}--- ///


int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  ll dp[N + 1]; // i離れたところを取り除いて自分のところがカウントされる確率
  for(int i = 0; i < n; i++) dp[i] = modinv(i + 1, mod);
  for(int i = 1; i < n; i++) (dp[i] += dp[i-1]) %= mod;
  ll ans = 0;
  auto range = [&](int l, int r) {
    if(l > r) return 0ll;
    ll res = dp[r];
    if(l-1>=0) res += mod - dp[l-1];
    res %= mod;
    return res;
  };
  for(int i = 0; i < n; i++) {
    // 0, i
    // 1, n - 1 - i
    ans += a[i] * (range(0, i) + range(1, n - 1 - i)) % mod;
    ans %= mod;
  }
  ans = (ans * fact[n]) % mod;
  cout << ans << endl;
  return 0;
}
