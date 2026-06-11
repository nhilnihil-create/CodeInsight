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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    ans+=(a<=b)?a:b;
    ans+=(c<=d)?c:d;
    cout<<ans<<endl;
}