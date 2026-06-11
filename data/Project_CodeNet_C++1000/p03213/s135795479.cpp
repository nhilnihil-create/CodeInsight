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

int dp[100][77];
int main(){
  int N;
  scanf("%d", &N);
  std::map<int, int> mp;
  for (int i=2; i<=N; i++){
    int n=i;
    for (int j=2; j*j<=n; j++){
      while (n%j==0){
	mp[j]++;
	n=n/j;
      }
    }
    if (n!=1){
      mp[n]++;
    }
  }
  dp[0][1]=1;
  int i=0;
  for (auto &entry: mp){
    int num=entry.second;
    //printf("num=%d\n", num);
    for (int j=0; j<=num; j++){
      for (int k=0; k<77; k++){
	if (k*(j+1)>76) break;
	dp[i+1][k*(j+1)] += dp[i][k];
	//if (dp[i+1][k+j]!=0){
	//  printf("dp[%d][%d]=%d\n", i+1,k+j,dp[i+1][k+j]);
	//}
      }
    }
    i++;
  }
  std::cout << dp[i][75] << std::endl;
  return 0;
}