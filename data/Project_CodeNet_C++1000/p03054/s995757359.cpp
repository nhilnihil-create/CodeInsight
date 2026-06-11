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
  int W, H, N;
  scanf("%d", &H);
  scanf("%d", &W);
  scanf("%d", &N);
  int Sr, Sc;
  scanf("%d", &Sr);
  scanf("%d", &Sc);
  std::string S, T;
  std::cin >> S >> T;
  int safestep[4];
  char moji[4]={'U', 'R', 'D', 'L'};
  safestep[0]=Sr;
  safestep[1]=W-Sc+1;
  safestep[2]=H-Sr+1;
  safestep[3]=Sc;
  for (int i=0; i<4; i++){
    //printf("i=%d\n", i);
    int step=0;
    for (int j=0; j<N; j++){
      //printf("j=%d\n", j);
      if (S[j]==moji[i]){
	step++;
      }
      if (step>=safestep[i]){
	printf("NO\n");
	return 0;
      }
      if (T[j]==moji[(i+2)%4]){
	step=std::max(step-1, -safestep[(i+2)%4]+1);
      }
    }
  }
  printf("YES\n");

  return 0;
}
