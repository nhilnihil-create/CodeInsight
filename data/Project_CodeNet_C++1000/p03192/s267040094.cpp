//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,n,k;
    cin>>n;
    ll ans=0;
    while(n>0)
    {
     if(n%10==2)
     ans++;
     n/=10;
     
    }

    cout<<ans<<endl;

    return 0;
}



