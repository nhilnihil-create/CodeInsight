#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 自力で解けた。
const ll INF = 1e18;

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<ll> > C(10, vector<ll>(10, 0));
  rep(i, 10) rep(j, 10) cin >> C[i][j];

  vector<vector<int> > A(h, vector<int>(w, 0));
  rep(i, h) rep(j, w) cin >> A[i][j];

  rep(k, 10) {
    rep(i, 10) {
      rep(j, 10) {
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
      } 
    } 
  }

  ll ans = 0;
  rep(i, h) rep(j, w) {
    if (A[i][j] == -1) continue;
    ans += C[A[i][j]][1]; 
  }

  cout << ans << endl;
  return 0;
}
