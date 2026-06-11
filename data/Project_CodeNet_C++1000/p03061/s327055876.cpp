#include <bits/stdc++.h>

using namespace std;
#define sz(a) int(a.size())
#define ll  long long int
#define mod (long long)(1e9+7)
#define endl '\n'
#define ENGZ ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0) , cout.tie(0) ;
#define pi (acos(-1))
#define F first
#define S second

ll fp(ll n , ll p )
{
    if(p==0)
        return 1;
    if(p==1)
        return n ;
    ll res = fp(n,p/2)%mod ;
    res=((res)*(res))%mod ;
    if(p%2)
        res=(res*n)%mod ;
    return res ;
}


ll n , arr[100005] , a[100005],b[100005] ;
int main()
{
    ENGZ;

    cin>>n ;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i] ;
        a[i] = __gcd(arr[i],a[i-1]);
    }
    ll ans = a[n] ;
    for(int i=n ; i>=1 ; i--)
    {
        b[i] = __gcd(b[i+1] , arr[i]);
    }
    for(int i=1 ; i<=n ; i++)
    {
        ans = max(ans , __gcd(b[i+1],a[i-1]));
    }
    cout<<ans <<endl  ;
    return 0;
}
