#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }


int dp[100001][3];
int abc[100001][3];


int main() {
  int N; cin >> N;
  rep(i, N) cin >> abc[i][0] >> abc[i][1] >> abc[i][2];

  rep(i, N) rep(j, 3) rep(x, 3) {
    if (j == x) continue;
    chmax(dp[i+1][x], dp[i][j] + abc[i][x]);
  }

  int ans = 0;
  rep(i, 3) chmax(ans, dp[N][i]);
  cout << ans << '\n';
}
