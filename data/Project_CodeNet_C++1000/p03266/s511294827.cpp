#include <iostream>
using namespace std;
typedef long long ll;
ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1){
      res *= a; if(mod>=1) res %= mod;
    }
    a *= a; if(mod>=1) a %= mod;
    n >>= 1;
  }
  return res;
}
int main(){
  ll n,k;
  ll a,b;
  cin >> n >> k;
  if(k%2==0){
    a = n/k;
    b = n/(k/2)-a;
  }else{
    a = n/k;
    b = 0;
  }
  cout << modpow(a,3,0)+modpow(b,3,0) << endl;
  return 0;
}