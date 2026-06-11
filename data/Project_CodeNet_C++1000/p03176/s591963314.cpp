// Sakhiya07 - Yagnik Sakhiya
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define ld long double

#define pll pair<ll,ll>
#define ff first
#define ss second

#define pb push_back
#define all(x) x.begin(),x.end()

#define MOD  1000000007
const int N = 100005; 

#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);srand(time(NULL));
struct ft 
{
    vector<ll> bit;
    ll n;
    ft(ll n1) 
    {
        n = n1;
        bit.assign(n,0);
    }
    ll sum(ll r) 
    {
        ll ret = 0;
        for(; r >= 0; r = (r&(r+1))-1)
            ret = max(ret,bit[r]);
        return ret;
    }
    void add(ll idx, ll d) 
    {
        for(; idx < n; idx = idx | (idx+1))
            bit[idx] = max(bit[idx],d);
    }
};   
void solve()
{
    ll n;
    cin >> n;
    ll h[n],a[n],b[n];
    for(ll i=0;i<n;i++)   cin >> h[i],b[i] = h[i];
    for(ll i=0;i<n;i++)   cin >> a[i];
    map<ll,ll> val;
    sort(b,b+n);
    for(ll i=0;i<n;i++)      val[b[i]] = i;
    for(ll i=0;i<n;i++)      h[i] = val[h[i]];
    ft ft1(n+2);
    for(int i=0;i<n;i++)
    {
        ll maxi = ft1.sum(h[i]);
        maxi += a[i];
        ft1.add(h[i],maxi);
    }
    ll ans = ft1.sum(n-1);
    cout<<ans;
}

int main()
{
    FAST;
    int t = 1;
 // cin >> t;
    for(int i=1;i<=t;i++)
    {
        solve();
    }
}

 /// 6 8 14 18 