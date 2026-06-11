#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
#include <string.h>
using namespace std;

#define N 5002
#define inf 4000000000000000000LL
int p[N];

long long dp[N][N];
long long leftMoveCost,rightMoveCost;

void solve() {
  int n;
  long long A,B;
  scanf("%d %lld %lld ", &n,&A,&B);
  leftMoveCost = B;
  rightMoveCost = A;
  for(int i=1;i<=n;++i) {
    int num;
    scanf("%d ",&num);
    p[num] = i;
  }
  fill((long long*)dp,(long long*)dp+N*N,inf);
  dp[0][0] = 0;
  for(int i=1;i<=n;++i) {
    int curInd = p[i];
    long long mini = inf;
    for(int j=0;j<=n;++j) {
      mini = min(mini, dp[i-1][j]);
      long long cost;
      if(j+1==curInd) {
        cost = 0;
      } else if(j+1<curInd) {
        cost = leftMoveCost;
      } else {
        cost = rightMoveCost;
      }
      dp[i][j] = cost + mini;
    }
  }
  long long ret = inf;
  for(int i=0;i<=n;++i) {
    ret = min(ret, dp[n][i]);
  }
  printf("%lld\n", ret);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
