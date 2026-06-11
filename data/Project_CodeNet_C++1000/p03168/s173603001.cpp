#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

// 入力
int N;

// DP テーブル
double dp[3010][3010] = {}; 

int main() {
  cin >> N;
  double p[N];
  FOR(i,0,N) cin >> p[i];
  
  //初期条件
  dp[0][0] = 1.0;

  // ループ
  FOR(i,0,N) {
    FOR(j,0,i+1) {
      dp[i+1][j+1] += dp[i][j]*p[i];
      dp[i+1][j] += dp[i][j]*(1.0-p[i]);
    }
  }
  
  double ans = 0.0;
  FOR(j,(N-1)/2+1,N+1) ans += dp[N][j];
  
  cout << fixed << setprecision(10) << ans << endl;
 
}