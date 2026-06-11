#include<bits/stdc++.h>
#define ll long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define N 300005
#define M 1000000007
#define pii pair<ll,ll>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
main()
{
    int n,m;
    cin>>n>>m;
    map<ll,ll>mp;
    ll now=0;
    ll ans=0;
    mp[0]++;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        now+=x;
        now%=m;
        ans+=mp[now];
        mp[now]++;
    }
    cout<<ans;
}

