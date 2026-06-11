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

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()
#define sortAl(v) sort(all(v))
#define sortAlr(v)          \
  sort(v.begin(), v.end()); \
  reverse(v.begin(), v.end())

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T &a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T &a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
#define INF LLONG_MAX

bool is_large(const vll &a, const vll &b) {
  if (a[0] > b[0]) {
    return true;
  } else if (a[0] == b[0]) {
    for (int i = 9; i > 0; i--) {
      if (a[i] > b[i]) {
        return true;
      } else if (a[i] < b[i]) {
        return false;
      }
    }
  }
  return false;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, m;
  cin >> n >> m;

  vll a(m);
  rep(i, m) {
    cin >> a[i];
  }

  ll need[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  vvll dp(n + 10, vll(10));

  rep(i, n) {
    if (i == 0 || dp[i][0] != 0) {
      FORm(it, a) {
        ll v = *it;

        // compare
        vll candidate = dp[i];
        candidate[0]++;
        candidate[v]++;

        vll &target = dp[i + need[v]];
        if (is_large(candidate, target)) {
          target = candidate;
        }
      }
    }
  }

  auto ans = dp[n];
  for (int i = 9; i > 0; i--) {
    rep(j, ans[i]) {
      cout << i;
    }
  }

  cout << endl;

  return 0;
}
