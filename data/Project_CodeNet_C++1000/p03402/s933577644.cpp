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

  ll a, b;
  cin >> a >> b;

  a--;
  b--;

  ll h, w;
  h = 100;
  w = 100;

  vs s;

  string initial;
  rep(i, 100) {
    initial += '#';
  }
  rep(i, 50) {
    s.push_back(initial);
  }
  initial = "";
  rep(i, 100) {
    initial += '.';
  }
  rep(i, 50) {
    s.push_back(initial);
  }

  ll i = 0;
  while (a) {
    s[2 * (i / 100)][i % 100] = '.';
    i += 2;
    a--;
  }

  i = 0;
  while (b) {
    s[51 + 2 * (i / 100)][i % 100] = '#';
    i += 2;
    b--;
  }
  cout << h << " " << w << endl;
  rep(y, 100) {
    cout << s[y] << endl;
  }

  return 0;
}
