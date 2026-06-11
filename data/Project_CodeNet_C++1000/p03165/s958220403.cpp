#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  string s,t;
  cin >> s >> t;
  ll n,m;
  n=s.size();
  m=t.size();
  ll i,j;
  vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
  vector<vector<ll>> par(n+1,vector<ll>(m+1,-1));
  for(i=0;i<=n;i++){
    dp[i][0]=0;
  }
  for(i=0;i<=m;i++){
    dp[0][i]=0;
  }
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      if(s[i-1]==t[j-1]){
        dp[i][j]=1+dp[i-1][j-1];
        par[i][j]=3;
      }
      else{
        if(dp[i-1][j] > dp[i][j-1]){
          dp[i][j]=dp[i-1][j];
          par[i][j]=1;
        }
        else{
          dp[i][j]=dp[i][j-1];
          par[i][j]=2;
        }
      }
    }
  }
  string ans="";
  // backtracking;
  i=n;
  j=m;
  while(par[i][j] != -1){
    if(par[i][j]==3){
      ans= s[i-1] + ans;
      i=i-1;
      j=j-1;
    }
    else if(par[i][j]==1){
      i=i-1;
    }
    else{
      j=j-1;
    }
  }
  cout << ans << endl;

}