#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#include<queue>
#include<cmath>
#include<stack>
#include <map>
#define ll long long int
#define skip cin>>ws;
#define vll vector<ll> 
#define vb vector<bool>
#define vpll vector<pair<ll,ll>>
#define vvll vector<vector<ll>>
#define pll pair<ll,ll>
#define vs vector<string>
#define vvpll vector<vector<pair<ll, ll>>>
#define pb push_back
#define pob pop_back()
#define MOD (ll)(1e9 + 7)
#define test ll t; cin>>t; while(t--)

using namespace std;

void enter(vll &ar)
{
    ll n = ar.size();
    for(ll i=0;i<n;i++) cin>>ar[i];
}

void show(vll &a)
{
    ll n = a.size();
    for(ll i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

void SieveOfErat1sthenes(int n, vll &pri) 
{ 
    vb prime(n+1, true); 
   
    for (int p=2; p*p<=n; p++) 
    { 
        
        if (prime[p] == true) 
        { 
            pri.pb(p);
            
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}

ll mo(ll a)
{
    return a%MOD;
}

vll dpw, dpb;

void func(vvll &tr, ll parent, ll anc)
{
    for(ll e: tr[parent])
    {
        if(e==anc) continue;

        if(dpw[e]==-1)
        {
            func(tr, e, parent);
        }

        if(dpb[e]==-1)
        {
            func(tr, e, parent);
        }
    }

    dpb[parent] = 1;
    dpw[parent] = 1;

    for(ll e: tr[parent])
    {
        if(e==anc) continue;

        dpb[parent] = mo(mo(dpb[parent])*mo(dpw[e]));
        dpw[parent] = mo(mo(dpw[parent])*mo(mo(dpw[e]) + mo(dpb[e])));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    if(n==1)
    {
        cout<<2<<"\n";
        return 0;
    }

    vvll tr(n+1);
    dpw.assign(n+1, -1);
    dpb.assign(n+1, -1);

    for(ll i=0;i<n-1;i++)
    {
        ll a, b;
        cin>>a>>b;

        tr[a].pb(b);
        tr[b].pb(a);
    }

    ll root = -1;

    for(ll i=1;i<=n;i++) 
    {
        if(tr[i].size()==1) 
        {
            root = i;
            break;
        }
    }

    func(tr, root, -1);

    ll ans = mo(mo(dpw[root]) + mo(dpb[root]));

    cout<<ans<<"\n";

    return 0;
}