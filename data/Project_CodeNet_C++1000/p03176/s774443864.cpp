/*
 *
 *    I am o0o0oo00.
 *
 */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll          long long
#define p7          1000000007
#define p9          998244353
#define pb          push_back
#define ff          first
#define ss          second
#define vll         vector<ll>
#define pll         pair<ll,ll>
#define vpll        vector<pll>
#define mll         map<ll,ll>
#define test        ll T;cin>>T;while(T--)
#define ad(a,n)     vll a;a.resize(n);for(ll i=0;i<n;i++)cin>>a[i];
#define as(a,n)     for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
#define all(x)      x.begin(),x.end()

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll powm(ll x, ll y, ll m = p7) {
    x = x % m; ll res = 1; while (y)
    {if (y & 1)res = res * x; res %= m; y = y >> 1; x = x * x; x %= m;} return res;
}
ll modi(ll a, ll m = p7) {return powm(a, m - 2, m);}
void yesno(bool f) {f ? cout << "YES" << endl : cout << "NO" << endl;}


void ss99()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

struct fenwick
{
    vll fn;
    ll n;
    fenwick() {}
    fenwick(ll n)
    {
        init(n);
    }
    void init(ll _n)
    {
        n = _n + 10;
        fn.clear(); fn.resize(n, 0);
    }
    void update(ll x, ll val)
    {
        x++;
        while (x < n)
        {
            fn[x] = max(fn[x], val);
            x += (x & (-x));
        }
    }
    ll query(ll x)
    {
        ll ans = 0;
        while (x)
        {
            ans = max(ans, fn[x]);
            x -= (x & (-x));
        }
        return ans;
    }
    ll query(ll l, ll r)
    {
        return query(r) - query(l - 1);
    }
};


int32_t main()
{
    ss99();
//    test
    {
        ll n; cin >> n;
        ad(h, n);
        ad(b, n);
        ll dp[n + 1] = {0};
        fenwick bit(n);
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll val = bit.query(h[i]);
            dp[i] = b[i] + val;
            bit.update(h[i], dp[i]);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}