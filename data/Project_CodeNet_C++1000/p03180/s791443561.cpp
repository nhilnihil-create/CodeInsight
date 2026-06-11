#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

const ll INF = 1e18;
ll n, m;
vector<ll> dp;
vector<vector<ll>> a;

// S\T
ll setMinus(ll s, ll t) { return s & (t ^ (m - 1)); }
ll cntOnes(ll s) {
  ll res = 0;
  REP(i, n) {
    if ((1LL << i) & s) {
      res++;
    }
  }
  return res;
}

ll calc(ll s) {
  if (dp[s] != -INF) {
    return dp[s];
  }
  // わけない
  ll res = 0;
  REP(i, n) FOR(j, i + 1, n) if (((1LL << i) & s) > 0 && ((1LL << j) & s) > 0) {
    res += a[i][j];
  }

  for (ll t = m - 1; t > 0; t--) {
    t = t & s;
    if (t == s || t == 0) {
      continue;
    }
    ll x = calc(t);
    ll y = calc(setMinus(s, t));
    chmax(res, x + y);
  }
  dp[s] = res;
  return res;
}

int main() {
  cin >> n;
  a = vector<vector<ll>>(n, vector<ll>(n));
  REP(i, n) REP(j, n) { cin >> a[i][j]; }
  m = 1LL << n;
  dp = vector<ll>(m, -INF);
  dp[0] = 0;
  cout << calc(m - 1) << endl;
}