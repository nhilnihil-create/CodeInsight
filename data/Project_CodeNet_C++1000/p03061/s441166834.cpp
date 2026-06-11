#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main()
{
   ll n;
   cin>>n;
   vector<ll> arr(n+1);
   for(ll i=1;i<=n;i++)
      cin>>arr[i];
   vector<ll> left(n+2);
   vector<ll> right(n+2);
   left[0] = right[n+1] = 0;

   for(ll i=1;i<=n;i++)
      left[i] = __gcd(left[i-1],arr[i]);
   for(ll i = n;i>=1;i--)
      right[i] = __gcd(right[i+1],arr[i]);

   ll ans = 1;
   for(int i=0;i<=(n+1);i++)
      ans = max(ans, __gcd(left[i-1],right[i+1]));
   
   cout<<ans;
   return 0;
}
