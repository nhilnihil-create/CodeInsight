#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

ll n;
ll f(ll x, ll th, ll fi, ll se){
  if (x > n) return 0;
  ll ret = 0;
  if (th > 0 && fi > 0 && se > 0) ret++;
  ret += f(x*10+3, th+1, fi, se);
  ret += f(x*10+5, th, fi+1, se);
  ret += f(x*10+7, th, fi, se+1);
  return ret;
}

int main(){
  cin >> n;
  cout << f(0, 0, 0, 0) << endl;
  
  return 0;
}