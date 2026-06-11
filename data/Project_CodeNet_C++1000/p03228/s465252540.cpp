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
    ll a,b;
    int k,i;
    cin>>a>>b>>k;
    for (i=0;i<k;i++)
    {
        if (i&1)
        {
            if (b&1)
                b--;
            a+=b/2;
            b/=2;
        }
        else
        {
            if (a&1)
                a--;
            b+=a/2;
            a/=2;
        }
    }
    cout<<a<<" "<<b<<endl;
}