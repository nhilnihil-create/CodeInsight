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
  int N;
  cin >> N;
  vector<ll> L;
  L.push_back(2);
  L.push_back(1);

  if(N<=1){
    cout << L.at(N) << endl;
    return 0;
  }

  for(int i=2;i<=N;i++){
    L.push_back(L.at(i-1)+L.at(i-2));
  }

  cout << L.at(N) << endl;
  
  return 0;
}
