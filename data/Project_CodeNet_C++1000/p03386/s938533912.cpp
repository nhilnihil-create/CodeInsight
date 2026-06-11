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
  ll A,B;
  int K;
  cin >> A >> B >> K;
  if(B-A+1<=2*K){
    for(ll i=A;i<=B;++i) cout << i << endl;
  }
  else{
    for(ll i=A;i<A+K;++i) cout << i << endl;
    for(ll i=B-K+1;i<=B;++i) cout << i << endl;
  }
  
  return 0;
}
