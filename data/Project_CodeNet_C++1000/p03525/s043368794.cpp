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

ll n;
ll ans = 0;
vll d;

vll t;

void dfs(ll idx) {
  if (idx == n) {
    ll lst = 0;
    ll v = INF;
    REP(i, 24) {
      if (t[i]) {
        chmin(v, i - lst);
        chmin(v, 24 - i + lst);
        lst = i;
      }
    }
    chmin(v, 24 - lst);
    chmin(v, lst);

    chmax(ans, v);
  }

  if (d[idx] == 0) {
    return;
  }

  if (t[d[idx]] == 0) {
    t[d[idx]] = 1;
    dfs(idx + 1);
    t[d[idx]] = 0;
  }

  if (t[24 - d[idx]] == 0) {
    t[24 - d[idx]] = 1;
    dfs(idx + 1);
    t[24 - d[idx]] = 0;
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  cin >> n;
  d = vll(n);

  t = vll(24);
  rep(i, n) {
    cin >> d[i];
  }

  if (n >= 25) {
    cout << 0 << endl;
    return 0;
  }

  dfs(0);

  cout << ans << endl;

  return 0;
}
