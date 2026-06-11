#include <bits/stdc++.h>
using namespace std;

// boost
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

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
// #define mod (998244353ll)

const long long INF = 1LL << 60;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, k;
  cin >> n >> k;
  k += 1;

  vll a(n);
  vll b(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
  }

  ll ans = 0;

  rep(bt, 32) {
    ll t = 1 << bt;
    if ((t & k) == 0)
      continue;

    ll mask = k - t;
    mask |= t - 1;

    ll s = 0;
    rep(i, n) {
      if ((mask | a[i]) > mask)
        continue;
      s += b[i];
    }
    chmax(ans, s);
  }

  cout << ans << endl;

  return 0;
}
