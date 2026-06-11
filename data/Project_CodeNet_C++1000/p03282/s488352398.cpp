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
  ll K;
  cin >> S >> K;
  if(K<S.size()) S=S.substr(0,K);

  for(int i=0;i<S.size() && i<K;++i){
    if(S.at(i)=='1') continue;
    cout << S.at(i) << endl;
    return 0;
  }

  cout << 1 << endl;

  return 0;
}
