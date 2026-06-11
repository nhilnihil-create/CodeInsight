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

// DP[i][j]:i番目までの数値をチェックした時、i番目の数値が左からj番目に小さい時のパターン数
ll dp[3001][3001];
ll dps[3001][3001];

int main(){
  int n;cin>>n;
  string s;cin>>s;

  dp[0][0]=1;
  rep(i, n-1){

    dps[i][0] = dp[i][0];
    rep1(j, i+1){
      dps[i][j] += dps[i][j-1]+dp[i][j];
    }

    rep(j, i+1+1){
      if(s[i]=='<'){

        if(j)dp[i+1][j] += dps[i][j-1];

//        rep(k, i+1)if(k<j)dp[i+1][j] += dp[i][k];
      }else{

        dp[i+1][j] += dps[i][i];
        if(j)dp[i+1][j] -= dps[i][j-1];

//        rep(k, i+1)if(k>=j)dp[i+1][j] += dp[i][k];
      }
      dp[i+1][j] %= MOD;
    }
  }

  ll result = 0;
  rep(j, n)result = (result + dp[n-1][j])%MOD;

  cout<<result<<endl;

  return 0;

rep(i, n+1){
  rep(j, n+1)cout<<dp[i][j]<<' ';
  cout<<endl;
}cout<<"---"<<endl;

  return 0;
}