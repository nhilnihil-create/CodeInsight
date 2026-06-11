#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd ( ll a , ll b)
{
    if( b== 0)
        return a;
    return gcd( b , a%b );
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll ans = gcd( a[0] , a[1]);
    for(int i =2;i<n;i++)
    {
        ans = gcd ( ans , a[i] );
    }
    cout<<ans;
}