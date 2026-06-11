#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  ll x,y;
  cin >> x >> y;
  
  ll ans = 0;
  while(x <= y)
  {
    ans++;
    x *= 2;
  }
  
  cout << ans << endl;
}
