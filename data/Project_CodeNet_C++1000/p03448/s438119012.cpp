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
  int A,B,C,X;
  cin >> A >> B >> C >> X;
  int ans=0;

  for(int i=0;i<=A;i++){
    if(X<500*i) break;
    for(int j=0;j<=B;j++){
      if(X<500*i+100*j) break;
      for(int k=0;k<=C;k++){
	if(X==500*i+100*j+50*k) ++ans;
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}
