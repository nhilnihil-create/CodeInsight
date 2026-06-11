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

std::map<char, int > mp;
long long mod = 1e9+7;

int main(){
  int N;
  scanf("%d", &N);
  std::string S;
  std::cin >> S;
  for (int i=0; i<S.length(); i++){
    int value = int(S[i])-int('a');
    mp[value]++;
  }
  long long ans = 1;
  for (auto &entry : mp){
    ans *= entry.second+1;
    ans %= mod;
  }
  ans--;
  //std::cout << dfs(3, 0, 0) << std::endl;
  std::cout << ans << std::endl;
  return 0;
}
