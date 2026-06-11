#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long inf = 1000000007;
  string s;
  cin >> s;
  n = s.size();
  long dp[n+1][4];
  for(int i = 0;i <= n;i++){
    for(int j = 0;j < 4;j++){
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for(int i = 0;i < n;i++){
    if(s.at(i) == 'A'){
      for(int j = 0;j < 4;j++){
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= inf;
      }
      dp[i+1][1] += dp[i][0];
      dp[i+1][1] %= inf;
    }
    else if(s.at(i) == 'B'){
      for(int j = 0;j < 4;j++){
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= inf;
      }
      dp[i+1][2] += dp[i][1];
      dp[i+1][2] %= inf;
    }
    else if(s.at(i) == 'C'){
      for(int j = 0;j < 4;j++){
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= inf;
      }
      dp[i+1][3] += dp[i][2];
      dp[i+1][3] %= inf;
    }
    else{
      for(int j = 0;j < 4;j++){
        dp[i+1][j] += 3*dp[i][j];
        dp[i+1][j] %= inf;
      }
      dp[i+1][1] += dp[i][0];
      dp[i+1][2] += dp[i][1];
      dp[i+1][3] += dp[i][2];
      dp[i+1][1] %= inf;
      dp[i+1][2] %= inf;
      dp[i+1][3] %= inf;
    }
  }
  cout << dp[n][3] << endl;
}