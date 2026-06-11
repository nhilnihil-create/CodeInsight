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

inline int read() {
  int n = 0, f = 1;
  char c;
  for (c = getchar(); c != '-' && (c < '0' || c > '9'); c = getchar())
    ;
  if (c == '-')
    f = -1, c = getchar();
  for (; c >= '0' && c <= '9'; c = getchar())
    n = (n << 3) + (n << 1) + (c & 15);
  return n * f;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  int n = read();

  multiset<int> a;
  rep(i, n) {
    int tmp = read();
    a.insert(tmp);
  }

  int ans = 0;

  while (a.size() >= 2) {
    int mx = *a.rbegin();
    int p2 = 2;
    while (p2 <= mx)
      p2 *= 2;
    if (p2 == mx - p2) {
      a.erase(a.lower_bound(mx));
      auto itr = a.lower_bound(mx);
      if (itr != a.end()) {
        a.erase(itr);
        ans++;
      }
    } else {
      a.erase(a.lower_bound(mx));
      auto itr = a.lower_bound(p2 - mx);
      if (*itr == p2 - mx) {
        ans++;
        a.erase(itr);
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
