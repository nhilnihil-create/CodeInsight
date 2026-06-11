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

double dp[305][305][305];
int flag[305][305][305];  // (c1, c2, c3) が計算済みである事をメモしておく

double f(const int& n, const int& c1, const int& c2, const int& c3) {
  if (flag[c1][c2][c3]) return dp[c1][c2][c3];  // 計算済みの結果を返す
  flag[c1][c2][c3] = 1;
  double p0 = (double)(n - c1 - c2 - c3) / n;
  double p1 = double(c1) / n;
  double p2 = double(c2) / n;
  double p3 = double(c3) / n;
  dp[c1][c2][c3] = 1 / (1 - p0);
  if (c1 > 0) dp[c1][c2][c3] += f(n, c1 - 1 , c2, c3) * p1 / (1 - p0);
  if (c2 > 0) dp[c1][c2][c3] += f(n, c1 + 1, c2 - 1, c3) * p2 / (1 - p0);
  if (c3 > 0) dp[c1][c2][c3] += f(n, c1, c2 + 1, c3 - 1) * p3 / (1 - p0);
  return dp[c1][c2][c3];
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int c1 = 0, c2 = 0, c3 = 0;
  rep(i, n) {
    int x; cin >> x;
    if (x == 1) c1++;
    else if (x == 2) c2++;
    else c3++;
  }

  flag[0][0][0] = 1;

  printf("%.10f\n", f(n, c1, c2, c3));

  return 0;
}
