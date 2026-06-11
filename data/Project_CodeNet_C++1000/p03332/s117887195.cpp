#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const ll mod = 998244353;
const int N = 3e5 + 10;
ll fact[N], invf[N];

ll pwr(ll a, ll n) {
  ll r = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) r = r * a % mod;
    a = a * a % mod;
  }
  return r;
}
ll inv(ll a) {
  return pwr(a, mod - 2);
}

void pre() {
  fact[0] = invf[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    invf[i] = inv(fact[i]);
  }
}

ll choose(ll n, ll r) {
  if (n < r || r < 0) return 0;
  ll res = invf[r] * invf[n - r];
  res %= mod;
  res *= fact[n];
  res %= mod;
  return res;
}

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  pre();

  ll n, a, b, k; cin >> n >> a >> b >> k;

  ll ans = 0;
  for (int na = 0; na <= n; na++) {
    ll left = k - na * a;
    if (left >= 0 && left % b == 0) {
      int nb = left / b;
      ans += choose(n, na) * choose(n, nb) % mod;
    }
  }
  ans %= mod;
  cout << ans << endl;


  return 0;
}
