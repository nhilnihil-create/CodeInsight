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
  int N, K;
  scanf("%d", &N);
  scanf("%d", &K);
  std::vector<int > A(N);
  std::vector<long long > Asum(N+2);
  Asum[0]=0;
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
    Asum[i+1]=Asum[i]+(long long)A[i];
  }
  std::vector<long long > cand;
  for (int i=0; i<N; i++){
    for (int j=i+1; j<N+1; j++){
      cand.push_back(Asum[j]-Asum[i]);
      //printf("cand=%lld\n", cand[cand.size()-1]);
    }
  }
  
  for (int i=45; i>=0; i--){
    std::vector<long long > cand_orig(cand.size());
    std::copy(cand.begin(), cand.end(), cand_orig.begin());
    cand.clear();
    long long unit = (long long )1<<i;
    for (int j=0; j<cand_orig.size(); j++){
      if ((unit & cand_orig[j]) !=0) cand.push_back(cand_orig[j]);
    }
    //printf("i=%d,size()=%ld\n", i, cand.size());    
    if (cand.size()<K){
      std::swap(cand, cand_orig);
    }
  }
  long long ans=((long long)1<<45)-1;
  for (int j=0; j<K; j++){
    ans = (ans & cand[j]);
  }
  std::cout << ans << std::endl;
  return 0;
}