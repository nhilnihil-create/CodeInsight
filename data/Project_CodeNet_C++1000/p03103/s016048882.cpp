#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1e9;
const long long INFL = 1LL<<60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<pair<ll, int>> ab;
  rep(i, n) {
    int a, b; cin >> a >> b;
    ab.emplace_back(a, b);
  }

  sort(ALL(ab));

  ll ans = 0;
  ll rem = m;
  for (auto& p : ab) {
    if (p.second <= m) {
      ans += p.first * p.second;
      m -= p.second;
    } else {
      ans += p.first * m;
      m = 0;
    }
    if (m <= 0) break;
  }

  cout << ans << endl;

  return 0;
}
