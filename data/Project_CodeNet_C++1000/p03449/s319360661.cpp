#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> vec(2,vector<int>(n));
  for(int i=0; i<2; ++i){
    for(int j=0; j<n; ++j){
      cin >> vec[i][j];
    }
  }
  int dp[2][n];
  dp[0][0] = vec[0][0];
  for(int i=1; i<n; ++i){
    dp[0][i] = dp[0][i-1] + vec[0][i];
  }
  for(int i=0; i<n; ++i){
    dp[1][i] = dp[0][i] + vec[1][i];
    if(i) dp[1][i] = max(dp[1][i], dp[1][i-1] + vec[1][i]);
  }
  cout << dp[1][n-1] << endl;
}