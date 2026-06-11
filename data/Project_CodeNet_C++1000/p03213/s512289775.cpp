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
  int over15=0, over25=0, over75=0, over5=0, over3=0;
  for (auto &entry: mp){
    if (entry.second>=4) {
      over5++;
    }
    if (entry.second>=2) {
      over3++;
    }
    if (entry.second>=14) {
      over15++;
    }
    if (entry.second>=24) {
      over25++;
    }
    if (entry.second>=74) {
      over75++;
    }
  }
  //printf("%d, %d\n", over5, over3);
  int ans =0;
  if (over5>=2 && over3>=3){
    ans += over5*(over5-1)/2*(over3-2);
  }
  if (over15>=1 && over5>=2){
    ans += over15*(over5-1);
  }
  if (over25>=1 && over3>=2){
    ans += over25*(over3-1);
  }
  if (over75>=1){
    ans += over75;
  }
  std::cout << ans << std::endl;
  return 0;
}