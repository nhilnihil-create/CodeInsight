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
  std::string s;
  std::cin >> s;
  int n = s.length();
  std::vector<char > notx;
  for (int i=0; i<n; i++){
    if (s[i]=='x') continue;
    notx.push_back(s[i]);
  }
  bool canreverse = true;
  int notxsize = notx.size();
  if (notxsize==0){
    printf("0\n");
    return 0;
  }
  for (int i=0; i<=(notxsize-1)/2; i++){
    if (notx[i]!=notx[notxsize-i-1]) {
      canreverse = false;
      break;
    }
  }
  if (!canreverse){
    printf("-1\n");
  } else {
    std::vector<int > gap(notxsize+1, 0);
    int counter = 0;
    for (int i=0; i<n; i++){
      if (s[i]!='x') {
        counter++;
      } else {
        gap[counter]++;
        //printf("gap[%d]++\n",counter);
      }
    }
    int ans = 0;
    for (int i=0; i<=notxsize/2; i++){
      //printf("ans+=|%d-%d|\n", gap[i],gap[notxsize-i]);
      ans += abs(gap[i]-gap[notxsize-i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
