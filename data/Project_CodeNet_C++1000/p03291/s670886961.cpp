#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
int main(){
  string s;cin >> s;
  int n=s.size();
  ll dp[n+1][4];
  memset(dp,0,sizeof(dp));
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<4;j++){
      if(s[i]=='?'){
        dp[i+1][j]+=dp[i][j]*3%mod;
        dp[i+1][j]%=mod;
      }
      else{
        dp[i+1][j]+=dp[i][j];
        dp[i+1][j]%=mod;
      }
    }
    if(s[i]=='A'||s[i]=='?'){
      dp[i+1][1]+=dp[i][0];
      dp[i+1][1]%=mod;
    }
    if(s[i]=='B'||s[i]=='?'){
      dp[i+1][2]+=dp[i][1];
      dp[i+1][2]%=mod;
    }
    if(s[i]=='C'||s[i]=='?'){
      dp[i+1][3]+=dp[i][2];
      dp[i+1][3]%=mod;
    }
  }
  cout << dp[n][3] << endl;
}