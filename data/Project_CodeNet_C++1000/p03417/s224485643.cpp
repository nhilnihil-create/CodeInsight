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
  long long H, M;
  scanf("%lld", &H);
  scanf("%lld", &M);
  if (H==1 && M==1){
    printf("1\n");
  } else if (H==1){
    printf("%lld\n", M-2);
  } else if (M==1){
    printf("%lld\n", H-2);
  } else {
    printf("%lld\n", (H-2)*(M-2));
  }
  return 0;
}
