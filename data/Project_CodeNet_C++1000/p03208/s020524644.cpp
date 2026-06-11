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
    cin>>n>>k;
    ll a[n],ans=0,mini=INT_MAX;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0; i<=n-k; i++)
    {
        mini=min(mini,abs(a[i]-a[i+k-1]));
    }


    cout<<mini<<endl;

    return 0;
}



