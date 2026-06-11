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
    ll n,m;
    cin>>n>>m;
    ll ans=(1900*m+100*(n-m))*(1<<m);
    cout<<ans<<endl;
}