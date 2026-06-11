#define _GLIBCXX_DEBUG //test only

#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  ll n;
  cin >> n;
  ll a,b,c;
  bool fin = false;
  for(a=1;a<=3500;a++)
  {
    for(b=1;b<=3500;b++)
    {
      ll l = a*b*4;
      ll r1 = n*b;
      ll r2 = n*a;
      ll r3 = n*a*b;
      ll ks = l-r1-r2;
      if(ks == 0) continue;
      if(ks < 0)
      {
        ks *= -1;
        r3 *= -1;
      }
      if(r3 <= 0) continue;
      c = r3/ks;
      if(c > 3500) continue;
      if(c*ks == r3)
      {
        printf("%lld %lld %lld", a,b,c);
        fin = true;
      }
      if(fin) break;
    }
    if(fin) break;
  }
}