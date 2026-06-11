#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
int main(void){
  ll aval,bval,abval,a,b,c,d;
  cin >> aval >> bval >> abval >>a >>b;
  c = max(a,b);
  d = min(a,b);
  if(2*abval>aval+bval){
    ll ans = aval*a+bval*b;
    cout << ans;
  }else if(a>b){
    if(2*abval>aval){
      ll ans = 2*abval*d+(c-d)*aval;
      cout << ans;
    }else{
      ll ans = 2*abval*d+(c-d)*2*abval;
      cout << ans;
    }
  }else{
     if(2*abval>bval){
      ll ans = 2*abval*d+(c-d)*bval;
      cout << ans;
    }else{
      ll ans = 2*abval*d+(c-d)*2*abval;
      cout << ans;
    }
  }
  
  return 0;            
}