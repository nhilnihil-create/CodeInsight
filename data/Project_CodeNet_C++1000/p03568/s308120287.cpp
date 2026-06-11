#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll odd =1;
    for( int i=0;i<n;i++)
    {
        cin>>a[i];
        if( a[i]%2==0)
            odd *= 2;

    }
    ll ans = pow( 3,n) - odd;
    cout<<ans;
}