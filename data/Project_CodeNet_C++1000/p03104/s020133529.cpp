#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

int main()
{
  ll a, b;
  cin >> a >> b;
  
  auto func = [](ll x)
  {
    ll ret;
    for(ll i = (x / 4) * 4; i <= x; i++)
    {
      ret ^= i;
    }
    return ret;
  };
  
  cout << (func(a - 1) ^ func(b)) << endl;
  
  return 0;
}