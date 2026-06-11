// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long
#define mpr make_pair 
typedef long long ll;
#pragma GCC optimize("Ofast")

const int maxn = 3e5+10;
const int N = 1e6+5;
const int mod = 998244353;
const int inf = 1e9+10;

int A, B, n, k;
int fac[maxn];

ll pw(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = pw(a,b/2); x = (x*x) % mod;
    if(b&1) x = (x*a) % mod;
    return x;
}

ll C(ll n, ll k)
{
    return (fac[n] * pw((fac[k] * fac[n-k]) % mod, mod-2)) % mod;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> A >> B >> k;
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = (fac[i-1] * i) % mod;

    ll ans = 0;
    for(int x = 0; x <= n; x++)
        if((k-A*x) % B == 0)
        {
            int y = (k-A*x)/B;
            if(y < 0 || y > n) continue;
            (ans += (C(n,x) * C(n,y)) % mod) %= mod;
        }
    cout<< ans;
}



