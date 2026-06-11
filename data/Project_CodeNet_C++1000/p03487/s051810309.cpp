#include<bits/stdc++.h>
#define ll long long
#define mod 838627288460106
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll n,x,y,i,j,ans=0;
    map<ll,ll>mp;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    mp[a[i]]++;

    for(auto s:mp)
    {
        x=s.first;
        y=s.second;
        if(x>y) ans+=y;
        else ans+=y-x;
    }

    cout<<ans<<endl;

    return 0;
}



