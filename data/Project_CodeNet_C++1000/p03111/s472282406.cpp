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

// 竹 l を使用して x の長さを作るのに必要なコスト
int calc(vector<int> l, int x) {
  sort(ALL(l));
  int ans = INF;
  for (int i = 0; i < (1<<l.size()); i++) {
    int mp = 0;
    int len = 0;
    for (int j = 0; j < l.size(); j++) {
      if ((i>>j) & 1) {
        if (len != 0) mp += 10;
        len += l[j];
      }
    }
    if (len == 0) continue;
    mp += abs(len - x);
    chmin(ans, mp);
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> l(n);
  rep(i, n) cin >> l[i];

  int p = int(pow(3, n));

  int ans = INF;
  for (int i = 0; i < p; i++) {
    vector<vector<int>> v(3);
    for (int j = 0; j < n; j++) {
      int x = (i / int(pow(3, j))) % 3;
      v[x].push_back(l[j]);
    }
    if (v[0].empty() || v[1].empty() || v[2].empty()) continue;
    int tmp = calc(v[0], a) + calc(v[1], b) + calc(v[2], c);
    chmin(ans, tmp);
  }

  cout << ans << endl;

  return 0;
}
