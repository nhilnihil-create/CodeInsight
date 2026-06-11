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
  vll a(n);
  rep(i, n) {
    cin >> a[i];
  }

  ll mx = -INF;
  ll idx = 0;
  rep(i, n) {
    if (mx < abs(a[i])) {
      idx = i;
      mx = abs(a[i]);
    }
  }

  vector<P> ans;

  rep(i, n) {
    if (idx != i) {
      ans.emplace_back(idx, i);
      a[i] += a[idx];
    }
  }

  if (a[idx] >= 0) {
    REP(i, n) {
      if (a[i] < a[i - 1]) {
        a[i] += a[i - 1];
        ans.emplace_back(i - 1, i);
      }
    }
  } else {
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > a[i + 1]) {
        a[i] += a[i + 1];
        ans.emplace_back(i + 1, i);
      }
    }
  }

  cout << ans.size() << endl;

  for (const auto& it : ans) {
    cout << it.first + 1 << " " << it.second + 1 << endl;
  }

  return 0;
}
