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
  std::vector<int > a(N), b(N);
  long long asum=0, bsum=0;
  for (int i=0; i<N; i++){
    scanf("%d", &a[i]);
    asum += a[i];
  }
  for (int i=0; i<N; i++){
    scanf("%d", &b[i]);
    bsum += b[i];
  }
  long long diff = bsum-asum;
  if (diff<0){
    printf("No\n");
  } else {
    long long areq=0, breq=0;
    for (int i=0; i<N; i++){
      if (a[i]>b[i]){
        breq+=a[i]-b[i];
      } else {
        if (a[i]%2==b[i]%2){
          areq += (b[i]-a[i])/2;
        } else {
          areq += (b[i]+1-a[i])/2;
          breq++;
        }
      }
    }
    //printf("areq=%lld, breq=%lld, diff=%lld\n", areq, breq, diff);
    if (areq>diff || breq>diff){
      printf("No\n");
    } else if (2*(diff-areq)==diff-breq){
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
