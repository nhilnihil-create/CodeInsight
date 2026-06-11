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
  std::vector<int > digit;
  int sign = 1;
  if (N==0){
    printf("0\n");
    return 0;
  }
  while(N!=0){
    if (abs(N)%2==1){
      digit.push_back(1);
      N -= sign;
    } else {
      digit.push_back(0);
    }
    sign *= -1;
    N = N/2;
  }
  for (int i=digit.size()-1; i>=0; i--){
    printf("%d",digit[i]);
  }
  printf("\n");
  return 0;
}
