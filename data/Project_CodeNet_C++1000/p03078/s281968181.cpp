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
  std::sort(BC.begin(), BC.end(), std::greater<long long>());
  std::vector<long long >ABC;
  for (int i=0; i<X; i++){
    for (int j=0; j<std::min((int)K, (int)BC.size()); j++){
      ABC.push_back(A[i]+BC[j]);
    }
  }
  std::sort(ABC.begin(), ABC.end(), std::greater<long long>());
  for (int i=0; i<K; i++){
    printf("%lld\n", ABC[i]);
  }
  return 0;
}
 