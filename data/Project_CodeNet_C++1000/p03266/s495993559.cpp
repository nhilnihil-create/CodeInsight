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

int main(){
  int N, K;
  scanf("%d", &N);
  scanf("%d", &K);
  long long ans = 0;
  if (K%2==0){
    int sho1 = N/K;
    int sho2 = N/(K/2)-sho1;
    ans = pow((long long)sho1, 3);
    ans += pow((long long)sho2, 3);
  } else {
    int sho = N/K;
    ans = pow((long long)sho, 3);
  }
  printf("%lld\n", ans);
  return 0;
}
