#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int>coins;
  coins.push_back(1);
  int p6 = 6, p9 = 9;
  while(p6<=n){coins.push_back(p6);p6*=6;}
  while(p9<=n){coins.push_back(p9);p9*=9;}
  vector<int>dp(n+1,n);
  dp[0]=0;
  for(int i=1;i<=n;i++){
    for(int coin:coins){
      if(i-coin>=0){dp[i] = min(dp[i],dp[i-coin]+1);}
    }
  }
  cout<<dp[n]<<endl;
}
