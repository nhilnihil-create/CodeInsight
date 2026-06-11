#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod=pow(10,9)+7;
int main(){
  ll n,k;
  cin>>n>>k;
  ll arr[n];
  for(ll i=0;i<n;i++){
    cin>>arr[i];
  }
  int dp[n+1][k+1];
  for(int i=0;i<=k;i++)dp[0][i]=1;
  for(int i=0;i<=n;i++)dp[i][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      int diff=(j-arr[i-1]);
      if(diff<=0)
        dp[i][j]=(dp[i][j-1] %mod +dp[i-1][j]%mod)%mod;
      else if(diff>0){
        int val=(dp[i-1][j] -dp[i-1][diff-1]);
        if(val<0)val=(val+mod)%mod;
        dp[i][j]=(val%mod +dp[i][j-1]%mod)%mod;
      }
    }
  }
  if(k==0)
    cout<<dp[n][k]<<endl;
  else{
    int val=dp[n][k]-dp[n][k-1];
    if(val<0)val=(val+mod)%mod;
    cout<<val<<endl;
  }
}