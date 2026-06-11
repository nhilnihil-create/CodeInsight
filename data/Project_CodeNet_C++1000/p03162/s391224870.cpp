#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  ll a[n][3];
  rep(i,n){
    rep(j,3){
      cin >> a[i][j];
    }
  }
  ll dp[n+1][3];
  rep(i,n+1){
    rep(j,3){
      dp[i][j]=0;
    }
  }
  for(int i=1;i<=n;i++){
    rep(j,3){
      rep(k,3){
        if(k==j){
          continue;
        }
        dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i-1][k]);
      }
    }
  }
  cout <<max(dp[n][0],max(dp[n][1],dp[n][2]));
}