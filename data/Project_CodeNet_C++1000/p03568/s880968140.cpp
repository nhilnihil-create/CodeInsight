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
  vector<int> A(N);
  int even=0;
  for(int i=0;i<N;++i){
    cin >> A.at(i);
    if(A.at(i)%2==0) ++even;
  }

  cout << pow(3,N)-pow(2,even) << endl;;
  
  return 0;
}
