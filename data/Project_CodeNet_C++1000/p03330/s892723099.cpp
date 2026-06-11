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
int N, C;
int D[33][33];
int c[504][504];
long long ans;
std::map<int, int >mp[3];

void evaluate(std::vector<int > vec){
  int color[3];
  color[0]=vec[0];
  color[1]=vec[1];
  color[2]=vec[2];
  if (color[0]==color[1] || color[1]==color[2] || color[2]==color[0]){
    return;
  }
  long long sum=0;
  //printf("(%d, %d, %d)\n", color[0], color[1], color[2]);
  for (int i=0; i<3; i++){
    for (auto &entry: mp[i]){
      sum+=(long long)entry.second * D[entry.first][color[i]];
    }
  }
  ans = std::min(ans, sum);
  return;
}

void dfs(std::vector<int > vec){
  //printf("dfs%d called\n", vec.size());
  if (vec.size()==3){
    evaluate(vec);
  } else {
    for (int i=0; i<C; i++){
      //printf("i=%d\n", i);
      vec.push_back(i);
      dfs(vec);
      vec.pop_back();
    }
  }
  return;
}

int main(){
  scanf("%d", &N);
  scanf("%d", &C);
  for (int i=0; i<C; i++){
    for (int j=0; j<C; j++){
      scanf("%d", &D[i][j]);
    }
  }
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      scanf("%d", &c[i][j]);
      c[i][j]--;
      mp[(i+j)%3][c[i][j]]++;
    }
  }
  
  std::vector<int > empty;
  ans = 1e15;
  dfs(empty);
  std::cout << ans << std::endl;
  return 0;
}