#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

const int N = 1e6;

using namespace std;

main()
{
    fast;
    ll n,p,i;
    cin>>n>>p;
    map<ll,int> factorization;
    ll k=p;
    for (i=2;i<=sqrt(p);i++)
    {
        while (k%i==0)
        {
            factorization[i]++;
            k/=i;
        }
    }
    if (k!=1)
        factorization[k]++;
    ll ans=1;
    for (auto e: factorization)
    {
        if (e.ss>=n)
        {
            ll cnt=e.ss/n;
            ans*=(ll)(pow(e.ff,cnt));
        }
    }
    cout<<ans<<endl;
}