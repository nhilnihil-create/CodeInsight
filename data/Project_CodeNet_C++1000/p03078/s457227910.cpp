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
  int X, Y, Z, K;
  scanf("%d", &X);
  scanf("%d", &Y);
  scanf("%d", &Z);
  scanf("%d", &K);
  std::vector<long long > A(X), B(Y), C(Z);
  for (int i=0; i<X; i++){
    scanf("%lld", &A[i]);
  }
  for (int i=0; i<Y; i++){
    scanf("%lld", &B[i]);
  }
  for (int i=0; i<Z; i++){
    scanf("%lld", &C[i]);
  }
  std::vector<long long > BC;
  for (int i=0; i<Y; i++){
    for (int j=0; j<Z; j++){
      BC.push_back(B[i]+C[j]);
    }
  }
  std::sort(BC.begin(), BC.end());
  std::sort(A.begin(), A.end(), std::greater<int>());
  
  long long min = 1;
  long long max = 2e18;
  while(max-min>1){
    long long mid = (min+max)/2;
    int count = 0;
    for (int i=0; i<X; i++){
      auto itr = std::lower_bound(BC.begin(), BC.end(), mid-A[i]);
      count += BC.end()-itr;
    }
    if (count<K){
      max=mid;
    } else {
      min=mid;
    }
  }
  long long thresh = min - 2;
  //printf("thresh=%lld\n", thresh);
  std::vector<long long > ans;
  for (int i=0; i<X; i++){
    auto itr = std::lower_bound(BC.begin(), BC.end(), thresh-A[i]);
    while(itr!=BC.end()){
      ans.push_back(A[i]+(*itr));
      itr++;
    }
  }
  std::sort(ans.begin(), ans.end(), std::greater<long long >());
  for (int i=0; i<K; i++){
    printf("%lld\n", ans[i]);
  }
  return 0;
}
 