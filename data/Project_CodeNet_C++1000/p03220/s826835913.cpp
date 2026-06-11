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
  int N,T,A,H;
  cin >> N >> T >> A;
  vector<int> temperature(N);
  int ans;
  double temp,dist=10000;
  for(int i=0;i<N;++i){
    cin >> H;
    if(fabs(T-H*0.006 - A)<dist){
      ans=i;
      dist=fabs(T-H*0.006 - A);
    }
  }

  cout << ans+1 << endl;

  return 0;
}
