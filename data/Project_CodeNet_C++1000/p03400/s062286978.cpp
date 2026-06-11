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
  int N,D,X;
  cin >> N >> D >> X;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin >> A.at(i);
  int sum=0;
  
  for(int i=0;i<N;i++){
    for(int j=1;j<=D;j++){
      if((j-1)%A.at(i)==0) ++sum;
    }
  }

  cout << sum+X << endl;
  
  return 0;
}
