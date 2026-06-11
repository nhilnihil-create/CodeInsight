#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  string S;
  cin >> S;
  int N = (int)S.size();
  //dp[i][j]:i文字目まで見たときに「ABC」のj文字目まで確定している状態の組み合わせ数
  vector<vector<int>> dp(N+10, vector<int>(4, 0));
  dp[0][0] = 1;
  for( int i = 1; i <= N; i++ ){
    //その文字を選ばなかった場合
    for( int j = 0; j <= 3; j++ ){
      if( S[i-1] == '?' ) dp[i][j] = dp[i-1][j]*3;
      else dp[i][j] = dp[i-1][j];
      dp[i][j] %= MOD;
    }
    //選んだ場合
    if( S[i-1] == 'A' ){
      dp[i][1] += dp[i-1][0];
      dp[i][1] %= MOD;
    }else if( S[i-1] == 'B' ){
      dp[i][2] += dp[i-1][1];
      dp[i][2] %= MOD;
    }else if( S[i-1] == 'C' ){
      dp[i][3] += dp[i-1][2];
      dp[i][3] %= MOD;
    }else{
      for( int j = 1; j <= 3; j++ ){
        dp[i][j] += dp[i-1][j-1];
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[N][3] << endl;


}