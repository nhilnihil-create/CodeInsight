#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;

int main(){
  int n; cin>>n;
  vector<ll> dp(n,0),num(200001,0);
  int log; cin>>log;
  dp[0]=1;
  for(int i=1;i<n;i++){
    int x; cin>>x;
    if(x!=log){
      dp[i]=dp[i-1]+num[log];
      dp[i]%=MOD;
      num[log]=dp[i];
      log=x;
    }else{
      dp[i]=dp[i-1];
    }
    if(i==n-1) dp[i]+=num[x];
  }
  cout<<dp[n-1]%MOD<<endl;
}