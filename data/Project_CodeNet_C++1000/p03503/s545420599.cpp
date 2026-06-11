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
long long sum[1023];

int main(){
  int N;
  scanf("%d", &N);
  int F[104][10];
  for (int i=0; i<N; i++){
    for (int j=0; j<10; j++){
      scanf("%d", &F[i][j]);
    }
  }
  int P[104][11];
  for (int i=0; i<N; i++){
    for (int j=0; j<11; j++){
      scanf("%d", &P[i][j]);
    }
  }
  for (int i=1; i<1024; i++){
    for (int k=0; k<N; k++){
      int count = 0;
      int power2=1;
      for (int j=0; j<10; j++){
        if ((i&power2)!=0 && F[k][j]==1){
          count++;
        }
        power2*=2;
      }
      sum[i] += P[k][count];
    }
    //printf("sum[%d] = %lld\n", i, sum[i]);
  }
  long long ans = -1e15;
  for (int i=1; i<1024; i++){
    ans = std::max(ans, (long long)sum[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
