#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int n;
long long a[100010][3];

long long dp[100010][3];

int main() {
  cin >> n;
  rep(i,n) rep(j,3) cin >> a[i][j];
  for(int i = 0;i < n;i++) {
    for(int j = 0;j < 3;j++) {
      for(int k = 0;k < 3;k++) {
        if(j == k) continue;
        chmax(dp[i+1][k],dp[i][j] + a[i][k]);
      }
    }
  }
  long long int res = 0;
  for(int i = 0;i < 3;i++) chmax(res,dp[n][i]);
  cout << res << endl;
}