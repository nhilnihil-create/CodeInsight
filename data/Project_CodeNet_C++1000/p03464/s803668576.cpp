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
  long long min=0;
  long long max=10e15;
  //  printf("initial [%lld, %lld]\n", min, max);
  while(max-min>1) {
    //printf("in [%lld, %lld]\n", min, max);
    long long mid = (min+max)/2;
    long long x=mid;
    for (int i=0; i<K; i++) {
      x=x-x%A[i];
    }
    //printf("x=%lld\n", x);
    if (x>=2){
      max=mid;
    } else {
      min=mid;
    }
    //printf("out [%lld, %lld]\n", min, max);
  }
  long long ans1=max; // 2以上となる最小のN
  min=0;
  max=10e15;
  while(max-min>1) {
    long long mid = (min+max)/2;
    long long x=mid;
    for (int i=0; i<K; i++) {
      x=x-x%A[i];
    }
    if (x<=2){
      min=mid;
    } else {
      max=mid;
    }
  }
  long long ans2=min;
  if (ans1>ans2){
    printf("-1\n");
  } else {
    std::cout<<ans1<<" "<< ans2<<std::endl;
  }
  return 0;
}
