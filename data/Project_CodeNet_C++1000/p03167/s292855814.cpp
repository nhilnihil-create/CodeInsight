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
int H,W;
vector<string> A;


// DP テーブル
long long dp[1010][1010] = {}; 

int main() {
  
  cin >> H >> W;
  A.resize(H);
  FOR(i,0,H) cin >> A[i];
  
  //初期条件
  dp[0][0] = 1;

  // ループ
  FOR(i,0,H) {
    FOR(j,0,W) {
      if (i+1 < H && A[i+1][j] == '.') { //先にi+1<Hを書かないとエラーになる
        (dp[i+1][j] += dp[i][j]) %= 1000000007;
      }
      if (j+1 < W && A[i][j+1] == '.') { 
        (dp[i][j+1] += dp[i][j]) %= 1000000007;
      }
    }
  }
  
  cout << dp[H-1][W-1] << endl;
 
}