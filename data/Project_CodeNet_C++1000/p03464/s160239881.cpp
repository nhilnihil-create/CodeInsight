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
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

int main(){
  int K;
  scanf("%d", &K);
  std::vector<long long > A(K);
  for (int i=0; i<K; i++){
    scanf("%lld", &A[i]);
  }
  std::vector<long long > min(K+4), max(K+4);
  min[K]=2;
  max[K]=2;
  if (A[K-1]!=2) {
    printf("-1\n");
    return 0;
  }
  long long mincand, maxcand;
  for (int i=K-1; i>=0; i--){
    min[i]=A[i]*((min[i+1]+A[i]-1)/A[i]);
    max[i]=A[i]*(max[i+1]/A[i])+A[i]-1;
    //printf("i=%d, min,mnax=(%lld, %lld)\n", i, min[i], max[i]);
    if (min[i]>max[i]){
      printf("-1\n");
      return 0;
    }
  }
  std::cout<<min[0]<<" "<< max[0]<<std::endl;
  return 0;
}
