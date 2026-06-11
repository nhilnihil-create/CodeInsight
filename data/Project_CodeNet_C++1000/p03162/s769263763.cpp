#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;

  vector<vector<int>> a(n+1,vector<int>(3,0));

  rep(i,n) cin >> a[i+1][0] >> a[i+1][1] >> a[i+1][2];

  vector<vector<int>> dp(n+1,vector<int>(3,0));
  rep(i,3) dp[0][i] = a[0][i];

  for(int i = 1; i <= n; i++){
    dp[i][0] = a[i][0] + max(dp[i-1][1],dp[i-1][2]);
    dp[i][1] = a[i][1] + max(dp[i-1][0],dp[i-1][2]);
    dp[i][2] = a[i][2] + max(dp[i-1][0],dp[i-1][1]);
  }

  cout << max(dp[n][0],max(dp[n][1],dp[n][2])) << endl;

  return 0;
}
