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
  std::vector<int > A(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  std::vector<long long > sum(N+1);
  sum[0]=0;
  for (int i=0; i<N; i++){
    sum[i+1] = sum[i] + (long long)A[i];
  }
  std::map<long long, int> mp;
  for (int i=0; i<=N; i++){
    mp[sum[i]]++;
  }
  long long ans = 0;
  for (auto &entry : mp){
    ans += (long long)entry.second*(entry.second-1)/2;
  }
  std::cout << ans << std::endl;
  return 0;
}
