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
  std::vector<int > b(N);
  for (int i=0; i<N; i++){
    scanf("%d", &b[i]);
  }
  std::vector<int > ans;
  for (int i=0; i<N; i++){
    int hit_index = -1;
    for (int j=0; j<b.size(); j++){
      if (b[j]==j+1){
        hit_index=j;
      }
    }
    if (hit_index==-1){
      printf("-1\n");
      return 0;
    }
    ans.push_back(hit_index+1);
    b.erase(b.begin()+hit_index);
  }
  std::reverse(ans.begin(), ans.end());
  for (int i=0; i<ans.size(); i++){
    std::cout << ans[i] << std::endl;
  }
  return 0;
}
