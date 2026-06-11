#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;

ll move(ll x, string s, V<char> tv, V<char> dv) {
  ll n = s.size();
  REP(i, tv.size()) {
    if (x < 0 || x > n - 1) break;
    if (s.at(x) == tv.at(i)) {
      if (dv.at(i) == 'L') x--;
      else x++;
    }
  }
  return x;
}

int main() {
  ll n, q; cin >> n >> q;
  string s; cin >> s;
  V<char> t(q), d(q);
  REP(i, q) cin >> t.at(i) >> d.at(i);
  ll lll=0, lr=n;
  while (lll < lr) {
    ll mid = (lll + lr) / 2;
    if (move(mid, s, t, d) < 0) lll = mid+1;
    else lr = mid;
  }
  ll rl=0, rr=n;
  while (rl < rr) {
    ll mid = (rl + rr) / 2;
    if (move(mid, s, t, d) >= n) rr = mid;
    else rl = mid + 1;
  }
  cout << rr-lr << endl;
  return 0;
}
