#include <bits/stdc++.h>
using namespace std;

using ll =                   long long int;
using pll =                  pair<ll, ll>;
using vll =                  vector<ll>;
#define endl                 "\n"
#define space                " "
#define TLE_na_ho            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX_SIZE             1024
#define MOD                  1000000007
#define pb                   push_back
#define fi                   first
#define se                   second
#define all(v)               v.begin(),v.end()
#define f(n)                 for(ll i=0;i<n;i++)
#define rep(i,a,n)           for(ll i=a;i<n;i++)
#define repe(i,a,n)          for(ll i=a;i<=n;i++)
#define repr(i,a,n)          for(ll i=a;i>=n;i--)
#define ain(arr,n)           for(ll i1=0;i1<n;i1++ ) cin>>arr[i1]
#define aout(arr,n)          for(ll i1=0;i1<n;i1++ ) cout<<arr[i1]<<space




int main()
{
    TLE_na_ho;
    //READ THE QUESTION PROPERLY!!
    ll t;
    t = 1;
    //cin>>t;
    while(t--)
    {
        ll n;
    cin >> n;

    vll a(n);
    for(auto &i : a)
    	cin>>i;

    vll prefix(n),suffix(n);
    prefix[0]=a[0];

    rep(i,1,n)
    {
    	prefix[i]=__gcd(prefix[i-1],a[i]);
    }

    suffix[n-1]=a[n-1];

    repr(i,n-2,0)
    {
    	suffix[i]=__gcd(suffix[i+1],a[i]);
    }

    ll ans=max(prefix[n-2],suffix[1]);

    rep(i,1,n-1)
    {
    	ans=max(ans,__gcd(prefix[i-1],suffix[i+1]));
    }

    cout<<ans;
    }

}
