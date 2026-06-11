#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

ll XOR (ll n)
{
    if (n<=0)
        return 0;
    if (n%4==0)
        return n;
    else if (n%4==1)
        return 1;
    else if (n%4==2)
        return n+1;
    else
        return 0;
}

main()
{
    fast;
    ll a,b;
    cin>>a>>b;
    cout<<(XOR(b)^XOR(a-1))<<endl;
}