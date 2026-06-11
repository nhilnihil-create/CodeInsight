#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    ll x,y;
    int ans=0;
    cin>>x>>y;
    while (x<=y)
    {
        ans++;
        x*=2;
    }
    cout<<ans<<endl;
}