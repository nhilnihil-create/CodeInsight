#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

vector<vector<int>> c(10, vector<int>(10));

void warshall_floyd(int n) {
  for (int k = 0; k < n; k++) {      // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ///////////////////////////////////////
  int h, w;
  cin >> h >> w;
  rep(i, 10) rep(j, 10) cin >> c[i][j];
  warshall_floyd(10);
  int g[h][w];
  int ans = 0;
  rep(i, h) rep(j, w) {
    cin >> g[i][j];
    if (g[i][j] == -1) continue;
    ans += c[g[i][j]][1];
  }
  /* rep(i, 10) {
    rep(j, 10) cout << c[i][j] << " ";
    cout << endl;
  } */
  cout << ans << endl;
  return 0;
}
