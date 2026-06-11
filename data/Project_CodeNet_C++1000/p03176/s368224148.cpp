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
#define ll long long
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

void SieveOfErat1sthenes(ll n, vll &pri) 
{ 
    vb prime(n+1, true); 
   
    for (ll p=2; p*p<=n; p++) 
    { 
        
        if (prime[p] == true) 
        { 
            pri.pb(p);
            
            for (ll i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}


struct segtree
{
    ll size;
    vector<long long> values;

    void init(ll n)
    {
        size = 1;

        while(size<=n)
        {
            size *= 2;
        }

        values.assign(2*size, 0LL);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if(rx-lx ==1)
        {
            values[x] = v;
            return;
        }

        ll m = (lx+rx)/2;

        if(i<m)
        {
            set(i, v, 2*x + 1, lx, m);
        }
        else
        {
            set(i, v, 2*x + 2, m, rx);
        }

        values[x] = max(values[2*x +1],  values[2*x + 2]);
    }

    void set(ll i, ll v)
    {
        set(i, v, 0, 0, size);
    }

    long long maxi(ll l, ll r, ll x, ll lx, ll rx)
    {
        if( lx >= r || rx <= l) return 0;
        if( lx >= l && rx <= r) return values[x];

        ll m = (lx + rx)/2;

        long long s1 = maxi(l, r, 2*x + 1, lx, m);
        long long s2 = maxi(l, r, 2*x + 2, m, rx);
        return max(s1, s2);
    }

    long long maxi(ll l, ll r)
    {
        return maxi(l, r, 0, 0, size);
    }

};

ll mo(ll a)
{
    return a%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vll h(n), a(n);
    enter(h);
    enter(a);

    ll k = n + 1;

    segtree st;
    st.init(k);

    for(ll i=0;i<n;i++)
    {
        ll ma = st.maxi(0, h[i]);
        st.set(h[i], a[i]+ma);
    }

    ll ans = st.maxi(0, n + 1);

    cout<<ans<<"\n";

    return 0;
}