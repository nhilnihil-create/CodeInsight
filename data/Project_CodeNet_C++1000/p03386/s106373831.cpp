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
    ll a,b,k,i;
    cin>>a>>b>>k;
    if ((b-a+1)<=2*k)
    {
        for (i=a;i<=b;i++)
            cout<<i<<endl;
    }
    else
    {
        for (i=a;i<a+k;i++)
            cout<<i<<endl;
        for (i=b-k+1;i<=b;i++)
            cout<<i<<endl;
    }
}