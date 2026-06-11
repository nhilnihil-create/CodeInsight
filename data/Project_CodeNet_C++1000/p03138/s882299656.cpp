#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[50],dp2[50],b[50];
signed main(){
  int N,K;
  cin>>N>>K;
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    for(int i=0;A>0;A/=2,i++)b[i]+=A%2;
  }
  for(int i=48;i>=0;i--){
    if((K>>i)&1){
      dp2[i]=dp2[i+1]+(N-b[i])*(1LL<<i);
      if(dp[i+1])dp[i]=max(dp[i+1]+max(b[i],N-b[i])*(1LL<<i),dp2[i+1]+b[i]*(1LL<<i));
      else dp[i]=dp2[i+1]+b[i]*(1LL<<i);
    }else{
      dp2[i]=dp2[i+1]+b[i]*(1LL<<i);
      if(dp[i+1])dp[i]=dp[i+1]+max(b[i],N-b[i])*(1LL<<i);
    }
  }
  cout<<max(dp[0],dp2[0])<<endl;
}