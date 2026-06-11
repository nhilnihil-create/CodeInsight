#include <cstdio>
#include <algorithm>
#include <stdint.h>

int ps[5005];
int64_t dp[5005];

int main(){
  int N,A,B;
  scanf("%d %d %d",&N,&A,&B);
  for(int i=1;i<=N;i++){
    scanf("%d",&ps[i]);
    for(int j=0;j<=N;j++){
      if(j<ps[i]){
	dp[j]+=A;
      }else if(j>ps[i]){
	dp[j]+=B;
      }
    }
    for(int j=1;j<=N;j++){
      dp[j]=std::min(dp[j],dp[j-1]);
    }
  }
  printf("%ld\n",dp[N]);
  return 0;
}
