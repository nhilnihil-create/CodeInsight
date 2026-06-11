#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

int main(){
  ll a, b;
  cin >> a >> b;
  a--;
  ll xa, xb;
  if (a < 0) xa = 0;
  else if (a % 2 == 1) xa = (a/2+1) % 2;
  else xa = a + ((a+1)/2 % 2);
  if (b % 2 == 1) xb = (b/2+1) % 2;
  else xb = b + ((b+1)/2 % 2);
  ll ans = 0;
  ll x = 0;
  while(xa || xb){
    if ( (xa & 1) != (xb & 1) ) ans += (1LL<<x);
    xa >>= 1; xb >>= 1;
    x++;
  }
  cout << ans << endl;
  
  return 0;
}