#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector<vector<int>> ans;
  rep(i, h) {
    rep(j, w) {
      if (a[i][j] %2 != 0) {
        if (j < w-1) {
          vector<int> tmp = {i, j, i, j+1};
          ans.push_back(tmp);
          a[i][j]--;
          a[i][j+1]++;
        } else if (i < h - 1) {
          vector<int> tmp = {i, j, i+1, j};
          ans.push_back(tmp);
          a[i][j]--;
          a[i+1][j]++;
        }
      }
    }
  }

  cout << ans.size() << endl;
  for (auto& v : ans) {
    cout << v[0]+1 << " " << v[1]+1 << " " << v[2]+1 << " " << v[3]+1 << endl;
  }

  return 0;
}
