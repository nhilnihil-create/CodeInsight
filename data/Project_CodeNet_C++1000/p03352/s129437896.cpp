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
  int X;
  cin >> X;

  int ans=1;
  int p=2;
  int i_max=32;
  while(2<i_max){
    for(int i=2;i<i_max;++i){
      int temp=pow(i,p);
      if(X<temp){
	i_max=i;
	break;
      }
      ans=max(ans,temp);
    }
    ++p;
  }

  cout << ans << endl;
  
  return 0;
}
