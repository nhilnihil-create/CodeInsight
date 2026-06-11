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

int use[34][100004];
int sum[34][100004];

int main(){
  int N, C;
  scanf("%d", &N);
  scanf("%d", &C);
  std::vector<int > s(N), t(N), c(N);
  for (int i=0; i<N; i++){
    scanf("%d", &s[i]);
    scanf("%d", &t[i]);
    scanf("%d", &c[i]);
    c[i]--;
    use[c[i]][s[i]]++;
    use[c[i]][t[i]+1]--;
  }
  for (int c=0; c<C; c++){
    for (int i=1; i<100003; i++){
      sum[c][i] = sum[c][i-1] + use[c][i];
      //printf("sum[%d][%d]=%d\n", c, i, sum[c][i]);
    }
  }
  int max=0;
  for (int i=0; i<100003; i++){
    int cnt=0;
    for (int c=0; c<C; c++){
      //printf("sum[%d][%d]=%d\n", c, i, sum[c][i]);
      if (sum[c][i]>0) cnt++;
    }
    //printf("i=%d, cnt=%d\n", i, cnt);
    max = std::max(max, cnt);
  }
  std::cout << max << std::endl;
  return 0;
}
