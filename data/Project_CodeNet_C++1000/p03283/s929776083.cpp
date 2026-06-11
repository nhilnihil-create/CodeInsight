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

int hit[504][200004];
int sum[504][200004];
int main() {
  int N, M, Q;
  scanf("%d", &N);
  scanf("%d", &M);
  scanf("%d", &Q);
  std::vector<int > L(M), R(M), p(Q), q(Q);
  for (int i=0; i<M; i++){
    scanf("%d", &L[i]);
    scanf("%d", &R[i]);
  }
  for (int i=0; i<Q; i++){
    scanf("%d", &p[i]);
    scanf("%d", &q[i]);
  }
  for (int i=0; i<M;i++){
    hit[L[i]][R[i]]++;
  }
  for (int i=1; i<=N; i++){
    for (int j=1; j<=N; j++){
      sum[i][j]=hit[i][j]-sum[i-1][j-1]+sum[i][j-1]+sum[i-1][j];
    }
  }
  for (int i=0; i<Q; i++){
    int ans = sum[q[i]][q[i]]-sum[p[i]-1][q[i]]-sum[q[i]][p[i]-1]+sum[p[i]-1][p[i]-1];
    std::cout << ans << std::endl;
  }
  return 0;
}