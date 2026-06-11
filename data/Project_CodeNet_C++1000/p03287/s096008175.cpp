#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int, int>
#define PII pair<ll, ll>
#define llu long long unsigned
#define ld long double

const ll MAX = 1e18 + 100;
const ll Max = 1e9 + 500;

map<ll,ll> mp;


int main()
{
   ll t, i, j, k, p, q, a, b, c, mx, n, m, x, y;
   
   cin>>n>>m;

   ll sum=0;
   mp[0]=1;
   ll ans=0;

   for(i=1;i<=n;i++){
      cin>>x;
      sum=(sum  + x) % m;
      ans+= mp[sum];
      ++mp[sum];
   }

   cout<<ans<<'\n';
   
}