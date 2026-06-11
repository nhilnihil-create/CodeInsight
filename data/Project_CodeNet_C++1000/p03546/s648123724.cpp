#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

const int INF = 1000000000;
int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> dp(10, vector<int>(10, INF));
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, 10)rep(j, 10) cin >> dp[i][j];
  rep(i, h)rep(j, w) cin >> a[i][j];
  rep(i, 10) dp[i][i] = 0;
  
  rep(k, 10)rep(i, 10)rep(j, 10){
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  }
  int ans = 0;
  rep(i, h)rep(j, w){
    if (a[i][j] == -1) continue;
    ans += dp[a[i][j]][1];
  }
  cout << ans << endl;
  
  return 0;
}