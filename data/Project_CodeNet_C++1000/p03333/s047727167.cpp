#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdint.h>

int64_t left[100005];
int64_t right[100005];

int main(){
  int64_t N;
  scanf("%ld",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%ld %ld",&left[i],&right[i]);
  }
  std::sort(left,left+N+1);
  std::reverse(left,left+N+1);
  std::sort(right,right+N+1);
  int64_t sum=0;
  for(int64_t i=0;i<=N;i++){
    if(left[i]>right[i]){
      sum+=2*(left[i]-right[i]);
    }
  }
  printf("%ld\n",sum);
  return 0;
}
