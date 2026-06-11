#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;

  ll ans=0;
  int index_w=-1;
  for(int i=0;i<S.size();++i){
    if(S.at(i)=='W'){
      if(index_w==-1){
	ans+=i;
	index_w=1;
	continue;
      }
      ans+=i-index_w;
      ++index_w;
    }
  }

  cout << ans << endl;

  return 0;
}
