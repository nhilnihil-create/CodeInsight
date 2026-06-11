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
  int N;
  scanf("%d", &N);
  std::vector<int > A(N+2);
  int sum  = 0;
  A[0]=0;
  A[N+1] = 0;
  for (int i=1; i<=N; i++){
    scanf("%d", &A[i]);
  }
  for (int i=0; i<=N; i++){
    sum += abs(A[i]-A[i+1]);
  }
  //printf("sum=%d\n", sum);
  for (int i=1; i<=N; i++){
    printf("%d\n", sum-abs(A[i-1]-A[i])-abs(A[i]-A[i+1])+abs(A[i-1]-A[i+1]));
  }
  return 0;
}
