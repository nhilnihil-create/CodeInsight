#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll M = 998244353;

ll n, a, b, k;
ll l;
ll fac[300005];
ll fiv[300005];
ll ans;

int main()
{
    scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
    fac[0] = 1;
    for(ll i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % M;
    fiv[n] = 1;
    ll x = fac[n];
    for(ll i = 0; (1 << i) <= M; i++)
    {
        if((1 << i) & (M - 2)) fiv[n] *= x, fiv[n] %= M;
        x *= x;
        x %= M;
    }
    for(ll i = n - 1; i >= 0; i--) fiv[i] = fiv[i + 1] * (i + 1) % M;
    for(ll i = 0; i <= n; i++)
    {
        if(k < i * a) break;
        if((k - i * a) % b != 0) continue;
        ll j = (k - i * a) / b;
        if(j > n) continue;
        ans += fac[n] % M * fiv[n - i] % M * fiv[i] % M * fac[n] % M * fiv[j] % M * fiv[n - j] % M;
        ans %= M;
    }
    printf("%lld\n", ans);
    return 0;
}
