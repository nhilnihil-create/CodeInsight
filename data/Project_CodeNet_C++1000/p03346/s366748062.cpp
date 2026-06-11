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

int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > P(N), position(N);
  for (int i=0; i<N; i++){
    scanf("%d", &P[i]);
    position[P[i]-1]=i;
  }
  int increase_max = 1;
  int temp=1;
  int index_old=N+4;
  for (int i=0; i<N; i++){
    int index=position[i];
    if (index_old>index){
      temp=1;
    } else{
      temp++;
      increase_max=std::max(increase_max, temp);
    }
    index_old=index;
  }
  std::cout << N-increase_max <<std::endl;
  return 0;
}