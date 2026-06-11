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
  std::string S;
  std::cin >> S;
  //std::vector<int > count(S.length()+4, 0);
  long long ans = 0;
  int counter = 0;
  int index = S.length()-1;
  char next = 'C';
  while(index>=0){
    if (S[index]=='A'){
      if (next=='C'){
        ans += counter;
      } else {
        counter = 0;
        next='C';
      }
    } else if (S[index]==next){
      if (next=='C'){
        next='B';
      } else if (next=='B'){
        next='C';
        counter++;
      }
    } else if (S[index]=='C'){
      next='B';
      counter=0;
    } else {
      counter = 0;
      next='C';
    }
    index--;
  }
  std::cout << ans << std::endl;
  return 0;
}
