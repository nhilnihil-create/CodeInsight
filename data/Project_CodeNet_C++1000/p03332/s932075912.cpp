#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = 3e5 + 5;
const int mod = 998244353;

vector < ll > fact(N);

ll pwr (ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

ll inv (ll a) {
  return pwr(a, mod - 2);
}

ll comb (int n, int r) {
  if (r > n) return 0;
  return ((((fact[n] * inv(fact[n - r])) % mod) * inv(fact[r])) % mod);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = (i * fact[i - 1]) % mod;

  ll n, a, b, k;
  cin >> n >> a >> b >> k;

  ll ans = 0;
  for (int x = 0; x <= n; x++) {
    ll y = (k - a * x) / b;
    if (y < 0) continue;
    if (a * x + b * y == k) {
      ans = (ans + ((comb(n, x) * comb(n, y)) % mod)) % mod;
    }
  }

  cout << ans << '\n';
}
