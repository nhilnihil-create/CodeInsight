#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
template <typename T>
ostream& operator<<(ostream& os, vector<T>& a) {
  for (int i = 0; i < (int)a.size(); ++i)
    os << a[i] << " \n"[i == (int)a.size() - 1];
  return os;
}

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int d[33][33], c[505][505];
int pre[3][33];

int main() {
  int n, m;
  cin >> n >> m;
  rep(i, 0, m) rep(j, 0, m) cin >> d[i][j];
  rep(i, 0, n) rep(j, 0, n) {
    cin >> c[i][j];
    --c[i][j];
  }

  // あまり3種類
  // それぞれを
  rep(a, 0, m) {
    rep(i, 0, n) {
      rep(j, 0, n) {
        int k = (i + j) % 3;
        pre[k][a] += d[c[i][j]][a];
      }
    }
  }
  int ans = INF;

  rep(i, 0, m) {
    rep(j, 0, m) {
      rep(k, 0, m) {
        if (i == j | j == k || k == i) continue;
        ans = min(ans, pre[0][i] + pre[1][j] + pre[2][k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
