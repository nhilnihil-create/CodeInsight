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
  int N, K;
  scanf("%d", &N);
  scanf("%d", &K);
  std::vector<int > x(N), y(N), xx(N), yy(N);
  for (int i=0; i<N; i++){
    scanf("%d", &x[i]);
    scanf("%d", &y[i]);
    xx[i]=x[i];
    yy[i]=y[i];
  }
  std::sort(xx.begin(), xx.end());
  std::sort(yy.begin(), yy.end());
  xx.erase(unique(xx.begin(), xx.end()), xx.end());
  yy.erase(unique(yy.begin(), yy.end()), yy.end());
  long long ans = 4e18+10;
  for (int i=0; i<xx.size(); i++){
    for (int j=0; j<yy.size(); j++){
      for (int k=i; k<xx.size(); k++){
	for (int l=j; l<yy.size(); l++){
	  int cnt = 0;
	  for (int n=0; n<N; n++){
	    if (x[n]>=xx[i] && x[n]<=xx[k] && y[n]>=yy[j] && y[n]<=yy[l]) cnt++;
	  }
	  if (cnt>=K) ans = std::min(ans, ((long long)xx[k]-xx[i])*((long long)yy[l]-yy[j]));
	}
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
 