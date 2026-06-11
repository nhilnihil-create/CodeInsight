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
  vector<int> a(N);

  ll ans=0;
  for(int i=0;i<N;++i){
    cin >> a.at(i);
    while(a.at(i)%2==0){
      ++ans;
      a.at(i)/=2;
    }
  }

  cout << ans << endl;

  return 0;
}
