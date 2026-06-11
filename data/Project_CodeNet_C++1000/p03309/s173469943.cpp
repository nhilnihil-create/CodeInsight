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
#include <deque>

int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > A(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
    A[i]-=(i+1);
  }
  std::sort(A.begin(), A.end());
  int center = N/2;
  long long sum = 0;
  for (int i=0; i<N; i++){
    sum += abs(A[i]-A[center]);
  }
  printf("%lld\n", sum);
  return 0;
}
