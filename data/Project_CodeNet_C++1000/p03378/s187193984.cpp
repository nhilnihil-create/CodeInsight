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
  int N,M,X;
  cin >> N >> M >> X;
  vector<int> A(M);
  for(int i=0;i<M;i++) cin >> A.at(i);
  sort(A.begin(),A.end());

  int index;
  int cost_0=0,cost_N=0;
  for(int i=0;i<M;i++){
    if(A.at(i)<X){
      ++cost_0;
    }
    else{
      ++cost_N;
    }
  }

  cout << min(cost_0,cost_N) << endl;

  return 0;
}
