#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll k,a,b; cin >>k >>a >>b;
  if(b-a<=2 || k<=a){
    cout << k+1 << endl;
    return 0;
  }
  ll ans = a;
  ll t = k-a+1;
  if(t%2!=0) ans++;
  cout << ans+t/2*(b-a) << endl;
  return 0; 
}