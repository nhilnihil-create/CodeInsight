#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define DUMP(v) for(auto& x : v) cerr << x << " "; cerr << endl;
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, c;
  cin >> n >> c;

  vector<pair<int, int>> recorders(30, {0, -1});

  vector<vector<int>> programs(n);
  rep(i, n) {
    int s, t, c;
    cin >> s >> t >> c;
    programs[i] = {s, t, c};
  }

  sort(ALL(programs));

  for (auto& v : programs) {
    int s = v[0], t = v[1], c = v[2];
    for (auto& p : recorders) {
      if (p.first < s || p.first == s && p.second == c) {
        p.first = t;
        p.second = c;
        break;
      }
    }
  }

  ll ans = 0;
  for (auto& p : recorders) {
    if (p.first != 0) ans++;
  }

  cout << ans << endl;

  return 0;
}
