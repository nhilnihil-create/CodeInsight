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
  string N;
  cin >> N;

  if(N.size()==1){
    cout << N << endl;
    return 0;
  }

  int n_9=0;
  for(int i=1;i<N.size();++i){
    if(N.at(i)=='9') ++n_9;
  }

  if(n_9==N.size()-1){
    cout << 9*(N.size()-1)+stoi(N.substr(0,1)) << endl;
    return 0;
  }
  
  cout << (N.size()-1)*9+stoi(N.substr(0,1))-1 << endl;
  

  return 0;
}
