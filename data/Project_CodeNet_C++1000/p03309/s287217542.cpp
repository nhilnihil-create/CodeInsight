//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll i,t,n,j,ans=0;
    string s;
    cin>>n;
    ll a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]-=(i+1);
    }
    sort(a,a+n);
    ll subt=(n%2==0)?a[n/2-1]:a[n/2];
    for(i=0; i<n; i++)
    {
        ans+=abs(a[i]-subt);
    }


    cout<<ans<<endl;

    return 0;
}



