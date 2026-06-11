#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd ( ll a, ll b)
{
    if( b==0)
        return a;
    return gcd( b, a%b);
}
int main()
{
    ll n, x;
    cin>>n>>x;
    ll a[n+1];
    a[0] = x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a , a+n+1);
    ll temp = a[1] - a[0];
    ll ans =0;
    for(int i=0;i<n;i++)
    {
        ans = gcd( temp , a[i+1] - a[i] );
        temp = ans;
    }
    cout<<ans;
}