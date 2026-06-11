#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int dp[100010];
  dp[0]=0;
  for(int i=1;i<100010;i++){
    dp[i]=i;
    int x=1;
    while(x<=i){
      dp[i]=min(dp[i],dp[i-x]+1);
      x*=6;
    }
    x=1;
    while(x<=i){
      dp[i]=min(dp[i],dp[i-x]+1);
      x*=9;
    }
  }
  int n;
  cin>>n;
  cout<<dp[n]<<endl;
}