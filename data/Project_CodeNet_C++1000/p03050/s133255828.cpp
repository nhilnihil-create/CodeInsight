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

long long N;
std::map<long long, int > map;
long long ans;

void check(long long value){
  if (value==1) return;
  if (N/(value-1)==N%(value-1)){
    ans += value-1;
  }
  return;
}

void dfs(long long value, int num){
  //std::cout << "dfs(" << value << "," << num << ") called" << std::endl; 
  //std::cout << "1: mp size = " << map.size() << std::endl;
  if (num==map.size()){
    //printf("check (%lld)\n", value);
    check(value);
  } else {
    //std::cout << "2: mp size = " << map.size() << std::endl;
    long long power = 1;
    auto itr = map.begin();
    std::advance(itr, num);
    //std::cout << "3: mp size = " << map.size() << std::endl;
    //std::cout << map[num] << std::endl;
    //std::cout << "3.5: mp size = " << map.size() << std::endl;
    long long input = value;
    for (int i=0; i<=itr->second; i++){
      //std::cout << "4: mp size = " << map.size() << std::endl;
      //std::cout << "i=" << i << std::endl;
      dfs(input, num+1);
      input *= itr->first;
      //std::cout << "5: mp size = " << map.size() << std::endl;
    }
  }
}

int main(){
  ans = 0;
  scanf("%lld", &N);
  long long N_temp = N;
  for (long long i=2; i*i<=N_temp; i++){
    //printf("i=%d\n", i);
    while (N_temp%i==0){
      map[i]++;
      N_temp /= i;
    }
  }
  if (N_temp!=1){
    map[N_temp]++;
  }
  //std::cout << "size=" << map.size() << std::endl;
  dfs(1, 0);
  std::cout << ans << std::endl;
  return 0;
}
