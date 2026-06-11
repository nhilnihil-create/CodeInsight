#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

signed main(){
  string S, T;
  cin >> S >> T;
  vector<vector<int>> dp(3100, vector<int>(3100, 0));

  int s = (int)S.size();
  int t = (int)T.size();

  //LCSの長さを求める
  //dp[i][j]＝Sのi-1文字目までとTのi-1文字目までのLCSの長さ
  for( int i = 1; i <= s; i++ ){
    for( int j = 1; j <= t; j++ ){
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if( S[i-1] == T[j-1] ){
        dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
      }
    }
  }

  //文字列を後ろから復元する
  string ans = "";
  while( s > 0 && t > 0 ){
    if( dp[s][t] == dp[s-1][t] ) s--;
    else if( dp[s][t] == dp[s][t-1] ) t--;
    else{
      s--; t--;
      ans+= S[s];
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;

}