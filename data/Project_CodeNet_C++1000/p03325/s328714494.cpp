#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  ll n; cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  
  ll ans = 0;
  bool flag = false;
  while(1)
  {
    rep(i,n)
    {
      if(a[i] % 2 == 0)
      {
        a[i] /= 2;
        flag = true;
        ans++;
        break;
      }
    }
    
    if(flag == false)
    { 
      break;
    }
    flag = false;
  }
  
  cout << ans << endl;
}