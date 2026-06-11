#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;

int main(){
  int n;
  cin >> n;
  int a[n+1], b[n+1], c[n+1];
  int dp[n+1][3];
  for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
  for(int i = 0; i < 3; i++) dp[0][i] = 0;
  for(int i = 1; i <= n; i++){
    dp[i][0] = max(dp[i-1][1] + b[i], dp[i-1][2] + c[i]);
    dp[i][1] = max(dp[i-1][0] + a[i], dp[i-1][2] + c[i]);
    dp[i][2] = max(dp[i-1][0] + a[i], dp[i-1][1] + b[i]);
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}