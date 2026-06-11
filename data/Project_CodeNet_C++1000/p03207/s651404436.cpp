//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,j,n;
    cin>>n;
   ll x,ans=0,maxi=-1;
    while(n--)
        {
            cin>>x;
            maxi=max(maxi,x);
            ans+=x;
        }
    cout<<ans-(maxi/2)<<endl;

    return 0;
}



