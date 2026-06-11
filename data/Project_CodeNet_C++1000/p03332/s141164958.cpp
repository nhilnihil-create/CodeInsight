#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (int i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
using namespace std;
typedef long long int ll;

std::vector<ll> fac(3000000, 1), finv(3000000, 1), inv(3000000, 1);

void c4_init(ll m) {
    for (ll i = 2; i < 3000000; i++) {
        fac[i] = fac[i - 1] * i % m;
        inv[i] = m - inv[m%i] * (m / i) % m;
        finv[i] = finv[i - 1] * inv[i] % m;
    }
}

ll c4(ll n, ll k, ll m) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % m) % m;
}


const ll M = 998244353;
ll N, a, b, K, ans;

int main() {
  c4_init(M);
  cin >> N >> a >> b >> K;
  // ax + by = K
  // y = (K-ax)/b
  for (ll x = 0; x <= N; x++) {
    ll y = (K-a*x)/b;
    if (a*x + b*y == K) {
      //cout << "x = " << x << " y = " << y << endl;
      (ans += (c4(N, x, M) * c4(N, y, M)) % M) %= M;
    }
  }
  cout << ans << endl;
  return 0;
}
