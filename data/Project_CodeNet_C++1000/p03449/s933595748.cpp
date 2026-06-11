#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int ame[3][101];
int dp[3][101];
int main(){
  int n;cin >> n;
  rep(i,n) cin >> ame[0][i];
  rep(i,n) cin >> ame[1][i];
  dp[0][0] = ame[0][0];
  dp[1][0] = dp[0][0] + ame[1][0];

  for (int i = 0;i < 2;i++){
    for (int j = 0; j < n;j++){
      if (i == 0) dp[i][j+1] = max(dp[i][j+1],dp[i][j]+ame[i][j+1]);
      else dp[i][j+1] = max(dp[i-1][j+1]+ame[i][j+1],dp[i][j]+ame[i][j+1]);
    }
  }
  //rep(i,2){
  //  rep(j,n) cout << dp[i][j];
  //  cout << endl;
  //}
  cout << dp[1][n-1] << endl;

  

  return 0;

}