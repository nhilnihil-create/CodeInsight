//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,n,h,w,a,b;
    cin>>n>>h>>w;
    ll ans=0;
    while(n--)
    {
        cin>>a>>b;
        if(a>=h&&b>=w)
     ans++;
     
    }

    cout<<ans<<endl;

    return 0;
}



