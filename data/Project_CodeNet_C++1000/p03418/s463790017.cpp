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
#include <set>
#include <deque>

int main(){
  int N, K;
  scanf("%d", &N);
  scanf("%d", &K);
  long long ans = 0;
  for (int i=K+1; i<=N; i++){
    ans += (long long)(N/i)*(i-K)+std::max((N-(N/i)*i-std::max(K-1, 0)), 0);
    //printf("%lld + %d\n",(long long)(N/i)*(i-K), (N-(N/i)*i-(K-1)));
  }
  printf("%lld\n", ans);
  return 0;
}
