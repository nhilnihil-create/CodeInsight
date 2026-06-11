#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[200005];

int main(){
  int64_t N,X;
  scanf("%ld %ld",&N,&X);
  for(int i=1;i<=N;i++){
    scanf("%ld",&as[i]);
    as[i]+=as[i-1];
  }
  int64_t best=9e18;
  for(int64_t k=1;k<=N;k++){
    int64_t cost=(N+k)*X+5*as[N];
    for(int i=N-2*k;i>0;i-=k){
      if(cost>9e18-2*as[i]){
	cost=9e18;
	break;
      }
      cost+=2*as[i];
    }
    best=std::min(best,cost);
  }
  printf("%ld\n",best);
  return 0;
}
