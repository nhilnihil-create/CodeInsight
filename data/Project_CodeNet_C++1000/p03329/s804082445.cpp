#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

int N,i,dp[100001];

int main(void){
  cin >> N;
  for(i=0;i<=N;i++){
    dp[i]=0;
  }
  int q=6,w=9;
  for(i=1;i<=N;i++){
    if(i>=6*q){
      q = q * 6;
    }
    if(i>=9*w){
      w = w * 9;
    }
    if(i<6){
      dp[i]=i;
    }else if(i<9){
      dp[i] = min(dp[i-1]+1,dp[i-q]+1);
    }else if(i>=9){
      dp[i] = min(dp[i-1]+1,dp[i-q]+1);
      dp[i] = min(dp[i],dp[i-w]+1);
    }
  }
  printf("%d\n",dp[N]);
  return 0;
}
