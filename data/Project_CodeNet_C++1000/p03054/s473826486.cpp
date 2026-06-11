#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 200000;

int h, w, n, sr, sc;
char s[N + 1], t[N + 1];

int dp[N + 1][4];

int main() {
  scanf("%d%d%d%d%d%s%s", &h, &w, &n, &sr, &sc, s, t);
  dp[n][0] = 1;
  dp[n][1] = w;
  dp[n][2] = 1;
  dp[n][3] = h;
  for (int i = n - 1; i >= 0; i--) {
    rep(j, 4) dp[i][j] = dp[i + 1][j];

    if (t[i] == 'L' && dp[i][1] < w) dp[i][1]++;
    if (t[i] == 'R' && dp[i][0] > 1) dp[i][0]--;
    if (t[i] == 'U' && dp[i][3] < h) dp[i][3]++;
    if (t[i] == 'D' && dp[i][2] > 1) dp[i][2]--;

    if (s[i] == 'L') dp[i][0]++;
    if (s[i] == 'R') dp[i][1]--;
    if (s[i] == 'U') dp[i][2]++;
    if (s[i] == 'D') dp[i][3]--;

    if (dp[i][1] < dp[i][0] || dp[i][3] < dp[i][2]) {
      cout << "NO" << endl;
      return 0;
    } 
  }
  if (sc >= dp[0][0] && sc <= dp[0][1] && 
      sr >= dp[0][2] && sr <= dp[0][3]) cout << "YES" << endl;
  else cout << "NO" << endl;
  // rep(i, n + 1) {
  //   rep(j, 4) printf("%d ", dp[i][j]);
  //   printf("\n");
  // }
  return 0;
}