#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
std::vector<int > ReturnBit(long long val){
  std::vector<int > bit(45, 0);
  int counter = 0;
  while(val>0){
    bit[counter]=val%2;
    //printf("bit[%d]=%d\n",counter,bit[counter]);
    val = val/2;
    counter++;
  }
  std::reverse(bit.begin(), bit.end());
  return bit;
}

int main(){
  int N;
  long long K;
  scanf("%d",&N);
  scanf("%lld",&K);
  std::vector<long long > A(N);
  std::vector<int > sum(45, 0);
  for (int i=0; i<N; i++){
    scanf("%lld",&A[i]);
    std::vector<int > getbit = ReturnBit(A[i]);
    for (int j=0; j<45; j++){
      sum[j] += getbit[j];
    }
  }
  std::vector<int > Kbit = ReturnBit(K);
  std::vector<std::vector<long long > > dp(46, std::vector<long long> (2, -1));
  dp[0][0] = 0;
  long long ans = 0;
  for (int i=1; i<=45; i++){
    long long kurai = (long long)1<<(45-i);
    //printf("Kbit[%d]=%d, sum[%d]=%d\n",i-1,Kbit[i-1],i-1,sum[i-1]);
    //printf("kurai=%lld\n",kurai);
    if (Kbit[i-1]==0){
      if (dp[i-1][1]!=-1){
        dp[i][1] = dp[i-1][1] + std::max(sum[i-1], N-sum[i-1])*kurai;
      }
      dp[i][0] = dp[i-1][0] + sum[i-1]*kurai; // 0を選択
    } else {
      dp[i][0] = dp[i-1][0] + (N-sum[i-1])*kurai; // 1を選択
      dp[i][1] = dp[i-1][0] + sum[i-1]*kurai; // 0を選択
      if (dp[i-1][1]!=-1){
        dp[i][1] = std::max(dp[i][1], dp[i-1][1]+std::max(sum[i-1], N-sum[i-1])*kurai);
      }
    }
    //printf("dp[%d][1]=%lld\n",i,dp[i][1]);
    //printf("dp[%d][0]=%lld\n",i,dp[i][0]);
  }
  printf("%lld\n",std::max(dp[45][0],dp[45][1]));
  return 0;
}
