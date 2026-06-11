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

// i番目の数値までチェック済みの時、着目中の数値が左からj番目に小さいパターン数
ll dp[3001][3001];

int main(){
  int n;cin>>n;
  string s;cin>>s;

  dp[0][0]=1;

  rep(i, n-1)for(int j=0; j <= i+1; j++){
    if(s[i]=='<'){
      for(int k=0; k<j; k++){
        dp[i+1][j] += dp[i][k];
      }
    }else{
      for(int k=j; k<=i; k++){
        dp[i+1][j] += dp[i][k];
      }
    }
    dp[i+1][j] %= MOD;
  }

  int result = 0;
  rep(i, n)result = (result + dp[n-1][i])%MOD;
  cout << result << endl;

  return 0;

rep(i, n){
  rep(j, n)cout<<dp[i][j]<<' ';cout<<endl;
}

  return 0;
}
