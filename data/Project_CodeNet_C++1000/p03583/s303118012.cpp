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
  for (int n=1; n<=3500; n++){
    for (int h=1; h<=3500; h++){
      long long numerator = (long long)N*h*n;
      long long denomerator = (long long)4*n*h-(long long)N*n-(long long)N*h;
      if(denomerator>0 && numerator%denomerator==0){
        //printf("deno=%lld, nume=%lld\n", denomerator, numerator);
        printf("%d %d %lld\n", n, h, numerator/denomerator);
        return 0;
      }
    }
  }
  return 0;
}
