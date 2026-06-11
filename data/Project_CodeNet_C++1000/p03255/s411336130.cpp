#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N =  200100;
inline ll read()
{
  ll p=0; ll f=1; char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
  while(ch>='0' && ch<='9'){p=p*10+ch-'0'; ch=getchar();}
  return p*f;
}
ll a[N],s[N];
ll calc(ll l,ll r){return s[r] - s[l-1];}
int main()
{
  ll n = read(); ll x = read();
  for(ll i=1;i<=n;i++) a[i] = read();
  for(ll i=1;i<=n;i++) s[i] = s[i-1] + a[i];
  ll minx = (ll)1e55;
  for(ll k=1;k<=(n+1)/2;k++)
  {
    ll l = 0; ll r = n; ll ans = 0; ll v = 5;
    for(ll i=1;r>=1;i++)
    {
      l = max(1ll , r - k + 1);
      ans += calc(l,r) * v;
      if(ans + k*x > minx) break;
      r = l-1; if(i==1) continue;
      else v+=2;
    }
    minx = min(minx , ans + k*x);
    // printf("%lld %lld\n",k , ans + k*x);
  }
  return printf("%lld\n",minx + n*x),0;
}