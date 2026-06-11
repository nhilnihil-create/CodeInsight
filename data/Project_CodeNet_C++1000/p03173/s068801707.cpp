#include <bits/stdc++.h>
using namespace std;

#define pb(a) push_back(a)
#define ll long long int
#define vi vector<int>
#define loop(i, n) for(ll i=1;i<=n;i++)
#define loop0(i, n) for(ll i=0;i<n;i++)
#define in(i) scanf("%lld", &i);
#define out(i) printf("%d", i)

ll n, k, a[401];
ll dp[401][401];

ll solve(ll l, ll r)
{
  if(l>r)
    return LONG_MAX;
  if(dp[l][r]!=-1)
    return dp[l][r];
  if(l==r)
    return dp[l][r]=0;
  ll ans=LONG_MAX, finalI=l;
  for(ll i=0;i<r-l;i++)
  {
    ll temp=solve(l, l+i)+solve(l+i+1, r)+a[r]-a[l-1];
    if(temp<ans)
    {
      finalI=i+l;
    }
    ans=min(ans, temp);
  }
  return dp[l][r]=ans;
}
int main()
{
  memset(dp, -1, sizeof(dp));
  in(n);
  loop(i, n)
  {
    in(a[i]);
    a[i]+=a[i-1];
  }
  ll ans=solve(1, n);
  cout<<ans<<"\n";
}
