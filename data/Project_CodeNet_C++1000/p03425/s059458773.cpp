#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<ll> a(5, 0);

  rep(i, n) {
    string s; cin >> s;
    if (s[0] == 'M') a[0]++;
    else if (s[0] == 'A') a[1]++;
    else if (s[0] == 'R') a[2]++;
    else if (s[0] == 'C') a[3]++;
    else if (s[0] == 'H') a[4]++;
  }

  ll ans = 0;
  for (int bit = 0; bit < (1<<5); bit++) {
    bitset<5> bs(bit);
    if (bs.count() != 3) continue;
    ll tmp = 1;
    for (int i = 0; i < 5; i++) {
      if ((bit >> i) & 1 == 1) {
        tmp *= a[i];
      }
    }
    ans += tmp;
  }

  cout << ans << endl;

  return 0;
}
