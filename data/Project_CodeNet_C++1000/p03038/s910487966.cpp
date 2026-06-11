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


bool com(pair<ll,ll> &a , pair<ll,ll> &b)
{
    return (a.S > b.S);
}
ll n , m , arr[100005] , ans = 0 , sum = 0;
pair<ll , ll > brr[100005] ;
int main()
{
    ENGZ;
    cin>>n >>m ;
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i] ;
    }
    for(int i=0 ; i<m ; i++)
    {
        cin>>brr[i].S >> brr[i].F ;
    }
    sort(arr,arr+n);
    sort(brr,brr+m);
    reverse(brr,brr+m);
    ll i = 0 , cur = 0 ;

    while(i < n && cur < m)
    {
        if(brr[cur].S)
        {
            arr[i] = max(arr[i] , brr[cur].F);
            i++ ;
            brr[cur].S -- ;
            if(brr[cur].S == 0)cur++ ;
        }
    }
    for(int i=0 ; i<n ; i++)
        ans+= arr[i];
    cout<<ans <<endl ;
    return 0;
}
