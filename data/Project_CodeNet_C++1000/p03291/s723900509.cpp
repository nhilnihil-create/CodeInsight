// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#define MOD 1000000007
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
signed main(){
  string s;
  cin >> s;
  ll n=s.size();
  vector<vector<ll>> dp(n+1,vector<ll>(4,0));
  dp[n][3] = 1;
  dp[n][2] = 0;
  dp[n][1] = 0;
  dp[n][0] = 0;
  for(int i=n-1;i>=0;i--){
    for(int j=3;j>=0;j--){
      if(j<3){
        ll m1,m2;
        if(s[i]=='?'){
          m1 = 3;
        }else{
          m1 = 1;
        }
        if(s[i]-'A'==j||s[i]=='?'){
          m2 = 1;
        }else{
          m2 = 0;
        }
        dp[i][j] = m1*dp[i+1][j] + dp[i+1][j+1]*m2;
      }else{
        ll m;
        if(s[i]=='?') m = 3;
        else m = 1;
        dp[i][j] = dp[i+1][j]*m;
      }
      dp[i][j] %= MOD;
    }
  }
  cout << dp[0][0]<<endl;
}
