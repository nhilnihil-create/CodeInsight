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
constexpr int INF = 1e9;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int calc(string a, string b) {
  set<char> s;
  int ret = 0;
  for (auto& c : a) s.insert(c);
  for (auto&c : b) {
    if (s.count(c) > 0) {
      ret++;
      s.erase(c);
    }
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 1; i < n-1; i++) {
    chmax(ans, calc(s.substr(0, i), s.substr(i, n-i)));
  }

  cout << ans << endl;

  return 0;
}
