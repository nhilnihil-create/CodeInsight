#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
#define ll long long
using namespace std;


const int MOD = 1000000007;

int main() {
  string S; cin>>S;
  int n=S.size();
  vector<vector<ll>> dp(n+1, vector<ll>(4));
  dp[0][0]=1;
  rep(i, n) {
    rep(j, 4) {
      if (S[i]=='?') dp[i+1][j]+=dp[i][j]*3;
      else dp[i+1][j]+=dp[i][j];
      dp[i+1][j]%=MOD;
    }
    if (S[i]=='A'||S[i]=='?') dp[i+1][1]+=dp[i][0];
    if (S[i]=='B'||S[i]=='?') dp[i+1][2]+=dp[i][1];
    if (S[i]=='C'||S[i]=='?') dp[i+1][3]+=dp[i][2];
  }
  dp[n][3]%=MOD;
  cout<<dp[n][3]<<endl;
}