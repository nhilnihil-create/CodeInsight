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

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, k;
  cin >> n >> k;

  vector<P> sushi;
  rep(i, n) {
    ll t, d;
    cin >> t >> d;
    sushi.emplace_back(d, t);
  }
  sort(all(sushi), greater<P>());

  vector<bool> exist(n + 1);
  vector<P> ori; // ダブりなし
  vector<P> dup; // ダブったやつ

  ll sum = 0;
  rep(i, n) {
    if (!exist[sushi[i].second]) {
      exist[sushi[i].second] = true;
      if (ori.size() < k) {
        sum += sushi[i].first;
        ori.push_back(sushi[i]);
      } else {
        dup.push_back(sushi[i]);
      }
    } else {
      dup.push_back(sushi[i]);
    }
  }

  ll type = ori.size();

  ll tmp = 0;
  if (ori.size() < k) {
    while (ori.size() < k) {
      sum += dup[tmp].first;
      ori.push_back(dup[tmp++]);
    }
  }

  ll ans = sum + type * type;
  while (tmp < min(k, (ll)dup.size())) {
    ll cand = sum - ori[type - 1].first + dup[tmp].first + (type - 1) * (type - 1);
    chmax(ans, cand);

    sum = sum - ori[type - 1].first + dup[tmp].first;
    ori[type - 1] = dup[tmp];

    type--;
    tmp++;
  }

  cout << ans << endl;

  return 0;
}
