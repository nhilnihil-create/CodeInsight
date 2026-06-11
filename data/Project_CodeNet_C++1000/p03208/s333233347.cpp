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
  int N,K;
  cin >> N >> K;
  vector<int> h(N);
  for(int i=0;i<N;++i) cin >> h.at(i);
  sort(h.begin(),h.end());
  int ans=1000000000;
  for(int i=0;i<=N-K;++i){
    ans=min(ans,h.at(i+K-1)-h.at(i));
  }

  cout << ans << endl;

  return 0;
}
