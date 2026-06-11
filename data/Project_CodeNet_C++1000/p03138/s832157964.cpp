#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k,i,j,a,B[41] = {},c = (1LL<<40);scanf("%lld%lld",&n,&k);bool flag = 0;
  for(i=0;i<n;i++){
    scanf("%lld",&a);
    for(j=0;a;j++,a/=2) B[j] += a%2;
  }
  ll dp[42][2] = {};
  for(i=40;i>=0;i--){
    dp[i][0] = dp[i+1][0]+((k&c) ? n-B[i]:B[i])*c;
    if(k&c){
      if(B[i]>n-B[i]) flag = 1;
      dp[i][1] = max(dp[i+1][0]+B[i]*c,dp[i+1][1]+max(B[i],n-B[i])*c);
    }
    else if(flag) dp[i][1] = dp[i+1][1]+max(B[i],n-B[i])*c;
    c >>= 1;
  }
  printf("%lld\n",max(dp[0][0],dp[0][1]));
}