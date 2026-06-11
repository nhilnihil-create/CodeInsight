#include <bits/stdc++.h>

// #LIB#

using namespace std;
using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  vector<vector<ll>> maxl(100, vector<ll>(100, LLONG_MIN / 4)), maxr(100, vector<ll>(100, LLONG_MIN / 4));
  maxl[0][0] = maxr[0][0] = 0;
  repr(i, 1, n + 1) {
    set<ll> vs;
    ll sum = 0;
    rep(j, i) {
      sum += v[j];
      vs.insert(v[j]);
    }
    maxl[i][0] = sum;
    ll trash = 0;
    while (!vs.empty()) {
      auto p = vs.begin();
      sum -= *p;
      ++trash;
      vs.erase(p);
      maxl[i][trash] = sum;
    }
  }
  repr(i, 1, n + 1) {
    set<ll> vs;
    ll sum = 0;
    rep(j, i) {
      sum += v[n - 1 - j];
      vs.insert(v[n - 1 - j]);
    }
    maxr[i][0] = sum;
    ll trash = 0;
    while (!vs.empty()) {
      auto p = vs.begin();
      sum -= *p;
      ++trash;
      vs.erase(p);
      maxr[i][trash] = sum;
    }
  }
  ll ans = LLONG_MIN / 4;
  rep(ln, n + 1) rep(rn, n - ln + 1) {
    rep(lt, ln + 1) rep(rt, rn + 1) {
      if (ln + rn + lt + rt > k) continue;
      updatemax(ans, maxl[ln][lt] + maxr[rn][rt]);
    }
  }
  cout << ans << endl;
}
