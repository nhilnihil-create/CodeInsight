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


int main(){
  std::vector<bool> isprime(300000, true);
  int N;
  scanf("%d", &N);
  isprime[0]=false;
  isprime[1]=false;
  isprime[2]=false;
  for (int i=2; i<300000; i++){
    if (isprime[i]){
      for (int j=2*i; j<300000; j+=i){
	isprime[j]=false;
      }
    }
  }
  std::vector<int > ans;
  int counter=2;
  while(ans.size()<N){
    if (isprime[counter]&&counter%5==1){
      ans.push_back(counter);
    }
    counter++;
  }
  for (int i=0; i<ans.size(); i++){
    printf("%d%c",ans[i],(i!=ans.size()-1)?' ':'\n');
  }
  return 0;
}