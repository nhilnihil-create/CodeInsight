#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

int main(){
  ll h, w;
  cin>>h>>w;
  char a[h][w];
  for(ll i=0; i<h; i++){
    for(ll j=0; j<w; j++){
      cin>>a[i][j];
    }
  }
  ll dp[h][w];
  memset(dp, 0, sizeof(dp));
  dp[h-1][w-1]=1;
  for(ll i=h-1; i>=0; i--){
    for(ll j=w-1; j>=0; j--){
      if(a[i][j]=='.'){
      	if(i<h-1)dp[i][j] =(dp[i][j]+ dp[i+1][j])%mod;
        if(j<w-1)dp[i][j] =(dp[i][j]+ dp[i][j+1])%mod;
      }
    }
  }
  

  cout<<dp[0][0]%mod<<"\n";
  return 0;
}
