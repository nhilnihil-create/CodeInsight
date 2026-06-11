#include <bits/stdc++.h>
using namespace std;
int E[510][510]={};
int dp[510][510]={};
int main(){
  int N,M,Q,ans;
  cin>>N>>M>>Q;
  
  //入力
  int l,r;
  for(int i=1;i<=M;i++){
    cin>>l>>r;
    E[l][r]++;
  }
  
  //累積和計算
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      dp[i][j]=dp[i-1][j]+dp[i][j-1]+E[i][j]-dp[i-1][j-1];
    }
  }
  
  //キュー処理
  int p,q;
  for(int i=0;i<Q;i++){
    cin>>p>>q;
    ans=dp[q][q]-dp[p-1][q]-dp[q][p-1]+dp[p-1][p-1];
    cout<<ans<<endl;
  }
  return 0;
}

