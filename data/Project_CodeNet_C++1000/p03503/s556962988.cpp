#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<vector<vector<int>>> f(n, vector<vector<int>>(5, vector<int>(2)));
  rep(i, n) rep(j, 5) rep(k, 2) cin >> f[i][j][k];
  vector<vector<int>> p(n, vector<int>(11));
  rep(i, n) rep(j, 11) cin >> p[i][j];

  int ans = -INF;
  rep(bit, 1<<10) {
    if (bit == 0) continue;
    vector<int> c(n, 0);
    rep(i, n) rep(j, 5) rep(k, 2) {
      if ((bit & 1<<(j+5*k)) && f[i][j][k]) ++c[i]; 
    }
    int now = 0;
    rep(i, n) now += p[i][c[i]];
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}