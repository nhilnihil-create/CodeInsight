#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

ll dp[3300][3300];
ll dps[3300][3300];

int main(){
  int n;cin>>n;
  string s;cin>>s;

  dp[0][0]=1;
  rep(i, n-1){

    dps[i][0]=dp[i][0];
    rep1(j, n){
      dps[i][j] += dps[i][j-1]+dp[i][j];
    }

    rep(j, i+2){
      if(s[i]=='<'){
        if(j)dp[i+1][j] += dps[i][j-1];
      }else{
        dp[i+1][j] += dps[i][n];
        if(j)dp[i+1][j] -= dps[i][j-1];
      }
      while(dp[i+1][j]<0)dp[i+1][j]+=MOD;
      dp[i+1][j] %= MOD;
    }
  }

  ll result = 0;
  rep(i, n)result += dp[n-1][i];
  cout<<result%MOD<<endl;

  return 0;

rep(i, n){
rep(j, n)cout<<dp[i][j]<<' ';cout<<endl;
}

  return 0;
}