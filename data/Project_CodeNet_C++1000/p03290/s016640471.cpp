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
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

// x 問解いたときの最大スコア
ll calc(const vector<pair<ll, ll>>& pc, int mid) {
  int n = pc.size();
  ll ret = 0;
  for (int bit = 0; bit < (1<<n); bit++) {  // 全問解く問題を決める
    int x = mid;
    ll score = 0;
    for (int i = 0; i < n; i++) {
      if (!((bit>>i) & 1)) continue;
      score += pc[i].first * (i+1) * 100 + pc[i].second;
      x -= pc[i].first;
    }
    if (x < 0) continue;
    for (int i = n-1; i >= 0; i--) {
      if (((bit>>i) & 1)) continue;   // 全問解いているのでパス
      if (x >= pc[i].first) {
        x -= pc[i].first;
        score += (i+1) * 100 * pc[i].first + pc[i].second;  // ここに来たときは 次の bit に進んで良いはずだけど
      } else {
        score += (i+1) * 100 * x;
        break;
      }
    }
    chmax(ret, score);
  }
  return ret;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int d, g;
  cin >> d >> g;
  int n = 0;
  vector<pair<ll, ll>> pc;
  rep(i, d) {
    ll p, c;
    cin >> p >> c;
    n += p;
    pc.push_back({p, c});
  }

  int ub = n;
  int lb = 0;
  while (ub - lb > 1) {
    int mid = lb + (ub - lb) / 2;
    if (calc(pc, mid) >= g) ub = mid;
    else lb = mid;
  }

  cout << ub << endl;

  return 0;
}
