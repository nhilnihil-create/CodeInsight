#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

int M[3][30];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,C;
  cin >> N >> C;

  int D[500][500];
  rep(i, C) {
    rep(j, C) {
      cin >> D[i][j];
    }
  }

  rep(i, N) {
    rep(j, N) {
      int c; cin >> c;
      c--;
      M[(i+j)%3][c]++;
    }
  }

  int ans = 1e9;

  rep(i, C) {
    rep(j, C) {
      if(i == j) continue;
      rep(k, C) {
        if(i == k || j == k) continue;
        int sum = 0;

        rep(l, C) {
          sum += M[0][l] * D[l][i];
          sum += M[1][l] * D[l][j];
          sum += M[2][l] * D[l][k];
        }

        ans = min(ans, sum);
      }
    }
  }

  cout << ans << endl;
}
