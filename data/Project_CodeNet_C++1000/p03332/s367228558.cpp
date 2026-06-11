#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = (ll)998244353;
const ll HIGHINF = (ll)1e18;
ll MAX = 310000;

vll fac(MAX, 0), finv(MAX, 0), inv(MAX, 0);

ll initCombTable() {
  fac.at(0) = 1; fac.at(1) = 1;
  finv.at(0) = 1; finv.at(1) = 1;
  inv.at(1) = 1;
  rep(i, 2, MAX) {
    fac.at(i) = fac.at(i-1) * i % MOD;
    inv.at(i) = MOD - inv.at(MOD%i) * (MOD / i) % MOD;
    finv.at(i) = finv.at(i-1) * inv.at(i) % MOD;
  }
}

ll nCk(ll n, ll k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return fac.at(n) * (finv.at(k) * finv.at(n-k)%MOD) % MOD;
}

int main() {
  initCombTable();
  ll n, a, b, k; cin >> n >> a >> b >> k;
  ll ans = 0;
  REP(i, n+1) {  // i: aで塗る個数
    ll rc = i;
    if ((k-rc*a)%b != 0) continue;
    ll bc = (k-rc*a)/b;
    ans += (nCk(n, rc) * nCk(n, bc)) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
