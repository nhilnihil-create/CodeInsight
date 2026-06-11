#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<bitset>
using namespace std;
using ll = long long;
int main(){
  ll a, b;
  cin >> a >> b;
  ll e[100] = {};

  ll ans = 0;
  for(ll bit = 40; bit >= 0; bit--) {
    ll tmp = 0;
    if(bit == 0) {
      tmp = ((b - a) / (ll)pow(2, bit + 1) +
             max(min(b % (ll)pow(2, bit + 1), (ll)1),
                 min(a % (ll)pow(2, bit + 1), (ll)1))) % 2;
      //cout << tmp;
    } else {
      if(b >> bit & 1){
        tmp = 1 + b & 1;
      } else {
        tmp = 0;
      }
      if(a >> bit & 1){
        tmp += 1 + !(a & 1);
      }
      tmp %= 2;
    }
    if(tmp == 1) {
      //cout << 1;
      e[bit] = 1;
    } else {
      //cout << tmp;
      e[bit] = 0;
    }
  }
  ll sum = 0;
  
  for(ll bit = 40; bit >= 0; bit--) {
    sum += e[bit] << bit;
  }
  cout << sum << endl;


  return 0;
}