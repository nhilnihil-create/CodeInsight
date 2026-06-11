#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll a[n];
  ll dp[n+10][2];
  for(int i = 0; i < n; i++){
    dp[i][0] = 0;
    dp[i][1] = 0;
  }
  dp[0][0] = 0;
  dp[0][1] = -MOD;
    for(int i = 0; i < n; i++){
      ll temp;
        cin >> temp;
      a[i] = temp;
    }
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0]+a[i-1],dp[i-1][1]-a[i-1]);
        dp[i][1] = max(dp[i-1][0]-a[i-1],dp[i-1][1]+a[i-1]);
    }
    dp[n][0] = max(dp[n-1][0]+a[n-1],dp[n-1][1]-a[n-1]);
    cout << dp[n][0] << endl;

}