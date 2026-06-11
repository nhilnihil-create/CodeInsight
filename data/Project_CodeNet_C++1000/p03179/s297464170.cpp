#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int main(){
int64_t dp[3005][3005];
  dp[1][1]=1;
  int N; string s;
  cin>>N>>s;
  for(int i=2;i<=N;i++){
  if(s.at(i-2)=='>'){
  int64_t a=0;
    dp[i][i]=0;
    for(int j=i-1;1<=j;j--){
     a=(a+dp[i-1][j])%mod;
      dp[i][j]=a;
    }
  }else{
     int64_t a=0;
    dp[i][1]=0;
    for(int j=1;j<=i-1;j++){
     a=(a+dp[i-1][j])%mod;
      dp[i][j+1]=a;
  }
  }
  }int64_t ans=0;
    for(int i=1;i<=N;i++)
      ans=(ans+dp[N][i])%mod;
    cout<<ans<<endl;
   return 0;
}