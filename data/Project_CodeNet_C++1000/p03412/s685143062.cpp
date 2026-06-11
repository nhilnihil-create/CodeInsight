#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
const long long INF = 1LL << 60;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n;
  cin >> n;

  vll a(n), b(n);
  rep(i, n) {
    cin >> a[i];
  }
  rep(i, n) {
    cin >> b[i];
  }

  sort(all(a));
  sort(all(b));

  bitset<64> ans = 0;

  rep(bt, 29) {
    ll mask = 1 << (bt + 1);
    mask--;

    vll p(n), q(n);
    rep(i, n) {
      p[i] = a[i] & mask;
      q[i] = b[i] & mask;
    }
    sort(all(p));
    sort(all(q));

    ll cnt = 0;
    for (auto x : p) {
      ll vl = (1 << bt) - x;
      ll vr = (1 << (bt + 1)) - x;
      ll l = distance(q.begin(), lower_bound(all(q), vl));
      ll r = distance(q.begin(), lower_bound(all(q), vr));
      cnt += r - l;

      vl += (1 << (bt + 1));
      vr = (1 << (bt + 2)) - x;
      l = distance(q.begin(), lower_bound(all(q), vl));
      r = distance(q.begin(), lower_bound(all(q), vr));
      cnt += r - l;
    }

    if (cnt & 0x01) {
      ans[bt] = 1;
    }
  }

  cout << ans.to_ullong() << endl;

  return 0;
}
