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
  ll x;
  cin >> N >> x;
  vector<ll> a(N);
  ll a_all=0;
  for(int i=0;i<N;i++){
    cin >> a.at(i);
    a_all+=a.at(i);
  }
  if(a_all==x){
    cout << N << endl;
    return 0;
  }
  sort(a.begin(),a.end());
  
  int ans=0;
  ll a_sum=0;
  for(int i=0;i<N;i++){
    a_sum+=a.at(i);
    if(x<a_sum) break;
    ++ans;
  }

  if(ans==N) --ans;
  cout << ans << endl;

  return 0;
}
