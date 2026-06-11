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

ld calc(ll v) {
  ll sum = 0;
  ll tmp = v;
  while (tmp) {
    sum += tmp % 10;
    tmp /= 10;
  }
  return (ld)v / (ld)sum;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll k;
  cin >> k;

  const ld eps = 1e-16;

  vll ans;
  ans.push_back(1e15 - 1);
  ld mn = calc(1e15 - 1);
  ll v = 1e15 - 1;
  while (v) {
    ll keta = 1;
    while (keta * 1000 < v) {
      keta *= 10;
    }
    v -= keta;
    if (v == 0)
      break;
    ld c = calc(v);
    if (c <= mn + eps) {
      mn = c;
      ans.push_back(v);
    }
  }

  reverse(all(ans));
  rep(i, k) {
    cout << ans[i] << endl;
  }

  return 0;
}
