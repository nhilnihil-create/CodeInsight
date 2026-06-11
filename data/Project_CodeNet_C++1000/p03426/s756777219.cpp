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
  int H, W, D;
  scanf("%d", &H);
  scanf("%d", &W);
  scanf("%d", &D);
  int A[H][W];
  std::pair<int, int> where[90000+5];
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      scanf("%d", &A[i][j]);
      where[A[i][j]] = std::make_pair(i,j);
    }
  }
  int Q;
  scanf("%d", &Q);
  std::vector<int > L(Q), R(Q);
  for (int i=0; i<Q; i++){
    scanf("%d", &L[i]);
    scanf("%d", &R[i]);
  }
  // calc cummulateiv distance
  std::vector<long long > dist(H*W+4);
  for (int i=1; i<=D; i++){
    dist[i]=0;
    for (int j=i; j+D<=H*W; j++){
      dist[j+D]=dist[j]+abs(where[j].first-where[j+D].first)+abs(where[j].second-where[j+D].second);
    }
  }

  // evaluate
  for (int i=0; i<Q; i++){
    int ans = dist[R[i]]-dist[L[i]];
    printf("%d\n", ans);
  }
  return 0;
}
