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
// #define mod (998244353ll)

const long long INF = 1LL << 60;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, k, q;
  cin >> n >> k >> q;

  vll a(n);
  set<ll> values;
  rep(i, n) {
    cin >> a[i];
    values.insert(a[i]);
  }

  ll ans = INF;

  // mv以上の値だけを取り出した場合のX-Yの値
  for (const auto mv : values) {
    ll l = 0, r = 0;

    vll cand;

    while (l < n) {
      priority_queue<ll, vll, greater<ll>> que;

      while (r < n && a[r] >= mv) {
        que.push(a[r]);
        r++;
      }

      if (r - l >= k) {
        ll cnt = r - l + 1 - k;
        while (cnt--) {
          ll v = que.top();
          que.pop();

          cand.push_back(v);
        }
      }

      l = r + 1;
      r = l;
    }

    if (cand.size() >= q) {
      sort(all(cand));
      chmin(ans, cand[q - 1] - cand[0]);
    }
  }

  cout << ans << endl;

  return 0;
}
