#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
inline void chmax(int &x, int v) { if (x < v) x = v; }

string S;
int N, K;
int dp[301][301][302];
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> S >> K;
  N = S.length();
  rep(i, N) rep(j, N) rep(k, K+1) dp[i][j][k] = -INF;
  dp[0][N-1][0] = 0;
  int m = 0;
  for (int len=N; len>=2; len--) {
    rep(l, N) {
      int r = l+len-1;
      if (r >= N) break;
      rep(k, K+1) {
        if (dp[l][r][k] < 0) continue;
        chmax(dp[l+1][r-1][k+(S[l]!=S[r])], dp[l][r][k] + 2);
        chmax(dp[l+1][r][k], dp[l][r][k]);
        chmax(dp[l][r-1][k], dp[l][r][k]);
      }
    }
  }
  rep(i, N) rep(j, N) rep(k, K+1) chmax(m, dp[i][j][k] + (i<=j));
  cout << m << "\n";
  return 0;
}
