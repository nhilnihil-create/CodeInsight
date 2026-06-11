#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int h[n];
  int dp[n+1];
  dp[0] = 0;
  for(int i = 0; i < n; i++) cin >> h[i];
  for(int i = 1; i < n; i++){
    dp[i] = dp[i-1] + abs(h[i-1] - h[i]);
    if(i > 1) dp[i] = min(dp[i], dp[i-2] + abs(h[i-2] - h[i]));
  }
  cout << dp[n-1] << endl;
}