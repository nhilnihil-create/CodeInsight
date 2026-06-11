// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
//#define mp make_pair 
typedef long long ll;
#define int long long
#pragma GCC optimize("Ofast")

const int maxn = 2e5+10;
const int mod = 1e9+7;
const ll inf = 1e18+10;
//const int N = 2e6+10;

ll pw(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = pw(a,b/2); x = (x*x) % mod;
    if(b & 1) x = (x*a) % mod;
    return x;
}

ll repo(ll x)
{
    return pw(x,mod-2);
}

int n;
int a[maxn], ps[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin>> n;
    ll fac = 1;
    for(int i = 1; i <= n; i++) (fac *= i) %= mod;
    for(int i = 1; i <= n; i++)
        ps[i] = (ps[i-1] + (fac * repo(i)) % mod) % mod;
    ll ans = 0;
    for(int i = 1, val; i <= n; i++)
    {
        cin>> val;
        ll f = (ps[n-i+1] + ps[i] - fac) % mod;
        (ans += (f * val) % mod) %= mod;
    }
    cout<< (ans + mod) % mod;
}
