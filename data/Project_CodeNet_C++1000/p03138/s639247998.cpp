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
  return bit;
}

int main(){
  int N;
  long long K;
  scanf("%d",&N);
  scanf("%lld",&K);
  std::vector<long long > A(N);
  std::vector<int > count(45, 0);
  std::vector<int > returnbit;
  for (int i=0; i<N; i++){
    scanf("%lld", &A[i]);
    returnbit = ReturnBit(A[i]);
    for (int j=0; j<45; j++){
      count[j]+=returnbit[j];
      //printf("returnbit[%d]=%d\n",j,returnbit[j]);
    }
  }
  long long ans = 0;
  std::vector<int > mainbit = ReturnBit(K);
  int counter = 44;
  while(mainbit[counter]==0 && counter>0){
    counter--;
  }
  int select;
  long long current_sum = 0;
  //printf("counter=%d\n",counter);
  for (int i = 44; i>=0; i--){
    long long compval = (long long)1 << i;
    //printf("count[%d]=%d\n",i,count[i]);
    //printf("1 << %d = %lld\n",i,((long long)1<<i));
    if (compval+current_sum > K){
      select = count[i]; // select 0
    } else {
      select = std::max(count[i], N-count[i]);
      if (count[i]<N-count[i]){ // 1を選んだ時
        current_sum += compval;
      }
    }
    //printf("select=%d\n",select);
    //printf("ans+=%lld * %d\n",compval,select);
    ans += compval*select;
  }
  printf("%lld\n",ans);
  return 0;
}
