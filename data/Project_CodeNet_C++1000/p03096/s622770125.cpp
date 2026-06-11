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

int memo[200004];
int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > C(N);
  for (int i=0; i<N;i++){
    scanf("%d", &C[i]);
  }
  C.erase(unique(C.begin(), C.end()), C.end());
  std::vector<long long > dp(N+4);
  dp[0]=1;
  long long mod = 1e9+7;
  for (int i=0; i<200004;i++){
    memo[i]=-1;
  }
  for (int i=0; i<C.size(); i++){
    dp[i+1] = dp[i];
    if (memo[C[i]]!=-1){
      dp[i+1] += dp[memo[C[i]]];
      dp[i+1] %= mod;
    }
    memo[C[i]] = i+1;
    //printf("%d, dp=%d\n", C[i], dp[i+1]);
  }
  std::cout << dp[C.size()] << std::endl;
  return 0;
}