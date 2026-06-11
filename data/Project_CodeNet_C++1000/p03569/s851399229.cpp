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


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  string r = s;
  reverse(ALL(r));

  vector<char> x;
  rep(i, s.size()) {
    if (s[i] != 'x') x.push_back(s[i]);
  }

  vector<char> y = x;
  reverse(ALL(y));
  rep(i, x.size()) {
    if (x[i] != y[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  int ans = 0;
  int idx1 = 0;
  int idx2 = 0;
  for (int t = 0; t < (x.size() + 1) / 2; t++) {
    int num1 = 0, num2 = 0;
    while (s[idx1] == 'x') {
      idx1++;
      num1++;
    }
    while (r[idx2] == 'x') {
      idx2++;
      num2++;
    }
    ans += abs(num1 - num2);
    idx1++;
    idx2++;
  }

  cout << ans << endl;

  return 0;
}
