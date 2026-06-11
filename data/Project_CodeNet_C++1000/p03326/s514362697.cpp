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
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  long long x, y, z;
  std::vector<long long > sum[8];
  int signx[8]={1, -1, 1, -1, 1, -1, 1, -1};
  int signy[8]={1, 1, -1 , -1, 1, 1, -1, -1};
  int signz[8]={1, 1, 1, 1, -1, -1, -1, -1};
  for (int i=0; i<N; i++){
    scanf("%lld", &x);
    scanf("%lld", &y);
    scanf("%lld", &z);
    for (int j=0; j<8; j++){
      sum[j].push_back(signx[j]*x+signy[j]*y+signz[j]*z);
    }
  }
  for (int j=0; j<8; j++){
    std::sort(sum[j].begin(), sum[j].end(), std::greater<long long>());
  }
    
  long long ans = -1;
  for (int i=0; i<8; i++){
    long long temp=0;
    for (int j=0; j<M; j++){
      temp+=sum[i][j];
    }
    ans = std::max(ans, temp);
  }
  std::cout << ans << std::endl;
  return 0;
}