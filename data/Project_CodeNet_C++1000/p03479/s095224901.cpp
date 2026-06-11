#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll x, y;
  cin >> x >> y;
  
  ll i = x;
  ll cnt = 1;
  while(true){
    i += i;
    if(i>y) break;
    cnt++;
  }
  
  cout << cnt << endl;


  return 0;
}