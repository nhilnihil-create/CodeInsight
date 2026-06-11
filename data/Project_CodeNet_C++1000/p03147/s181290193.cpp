#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9 + 5;
constexpr long long INFLL = 1LL << 62;
constexpr double eps = (1e-9);

// [l, r)
int calc(vector<int>& h, const int& l, const int& r) {
  ll ans = 0;
  int mi = INF;
  for (int i = l; i < r; i++) {
    chmin(mi, h[i]);
  }
  for (int i = l; i < r; i++) {
    h[i] -= mi;
  }
  ans += mi;
  for (int i = l; i < r; i++) {
    if (h[i] == 0) continue;
    int j;
    for (j = i; j < r; j++) if (h[j] <= 0) break;
    ans += calc(h, i, j);
    i = j;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  int ans = calc(h, 0, n);

  cout << ans << endl;

  return 0;
}
