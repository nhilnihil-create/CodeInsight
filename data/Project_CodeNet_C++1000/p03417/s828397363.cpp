#include <iostream>
using namespace std;
using ll = long long;
int main(){
  ll n,m;
  cin >> n >> m;

  ll h = n-2 >= 0 ? n-2:0;
  ll w = m-2 >= 0 ? m-2:0;
  ll ans = h*w;
  if(n == 1 && m == 1) ans = 1;
  else if(n == 1) ans = m-2;
  else if(m == 1) ans = n-2;

  cout << ans << endl;
}
