#include <bits/stdc++.h>

using namespace std;
#define sz(a) int(a.size())
#define ll  long long
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

ll n , k , arr[101] ;


ll sol(int idx)
{
    ll a = 0 , b = 0 , tmp = 0 ;
    priority_queue<ll , vector<ll> , greater<ll>> pq ;
    for(int i=0 ; i<=idx ; i++)
    {
        while(sz(pq)>0)pq.pop() ;
        tmp = 0 ;
        for(int j=1 ; j<=i ; j++)
        {
            pq.push(arr[j]);
            tmp+=arr[j] ;
        }
        b = idx - i ;
        for(int j=n ; j>n-b ; j--)
        {
            pq.push(arr[j]);
            tmp+=arr[j] ;
        }
        b = k-idx ;
        while(sz(pq) && pq.top() <= 0 && b)
        {
            b -- ;
            tmp -= pq.top();
            pq.pop();
        }
        a = max(a , tmp);
    }
    return a ;
}
int main()
{
    ENGZ;
    cin>>n >>k ;
    for(int i=1 ; i<=n ; i++)
    {
        cin>>arr[i] ;
    }
    ll ans = 0 ;
    for(int i=1 ;i<=min(n,k) ; i++)
    {
        ans = max(ans , sol(i));
    }
    cout<<ans <<endl ;
    return 0;
}
