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
  int N,M;
  cin >> N >> M;
  vector<pair<ll,ll>> shop(N);
  for(int i=0;i<N;++i){
    cin >> shop.at(i).first >> shop.at(i).second;
  }
  sort(shop.begin(),shop.end());

  ll ans=0;
  ll buy=0;
  for(int i=0;i<N;++i){
    if(M-buy<=shop.at(i).second){
      ans+=shop.at(i).first*(M-buy);
      break;
    }
    ans+=shop.at(i).second*shop.at(i).first;
    buy+=shop.at(i).second;
  }

  cout << ans << endl;

  return 0;
}
