#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define chmax(x, y) do { x = max(x, y); } while(0)
#define chmin(x, y) do { x = min(x, y); } while(0)
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

ll N, Q;
string s;
char t[300000];
char d[300000];

bool check_l(ll m) {
  if (m <= -1) return true;
  if (m >= N) return false;
  rep(i, Q) {
    if (s[m] != t[i]) continue;
    if (d[i] == 'R') m++;
    if (d[i] == 'L') m--;
    if (m == -1) return true;
    if (m == N) return false;
  }
  return false;
}

bool check_r(ll m) {
  if (m <= -1) return false;
  if (m >= N) return true;
  rep(i, Q) {
    if (s[m] != t[i]) continue;
    if (d[i] == 'R') m++;
    if (d[i] == 'L') m--;
    if (m == -1) return false;
    if (m == N) return true;
  }
  return false;
}

signed main() {
  cin >> N >> Q >> s;
  rep(i, Q) {
    cin >> t[i] >> d[i];
  }

  ll p, q;
  {
    // 左端から落ちるならok
    ll ok = -1, ng = N;
    while (ok+1 < ng) {
      ll m = (ok + ng) / 2;
      (check_l(m) ? ok : ng) = m;
    }
    p = ok;
    // cout << "p = " << p << endl;
  }
  {
    // 右端から落ちるならok
    ll ok = N, ng = -1;
    while (ng+1 < ok) {
      ll m = (ok + ng) / 2;
      (check_r(m) ? ok : ng) = m;
    }
    q = ok;
    // cout << "q = " << q << endl;
  }
  cout << max(0LL, q - p - 1) << endl;

  return 0;
}
