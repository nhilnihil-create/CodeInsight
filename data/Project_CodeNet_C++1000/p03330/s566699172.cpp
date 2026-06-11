#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define INF 1e15
#define rep(i, n) for (i = 0; i < n; i++)

ll d[50][50], col[505][505], sum[3][50];
int main() {
  ll n, c, ans = INF, i, j, k, val;
  cin >> n >> c;
  rep(i, c) {
    rep(j, c) { cin >> d[i][j]; }
  }
  rep(i, n) {
    rep(j, n) {
      cin >> col[i][j];
      col[i][j]--;
    }
  }
  rep(i, n) {
    rep(j, n) {
      val = (i + j) % 3;
      rep(k, c) { sum[val][k] += d[col[i][j]][k]; }
    }
  }
  rep(i, c) {
    rep(j, c) {
      rep(k, c) {
        if (i != j && j != k && i != k)
          ans = min(ans, sum[0][i] + sum[1][j] + sum[2][k]);
      }
    }
  }
  cout << ans << endl;
}
