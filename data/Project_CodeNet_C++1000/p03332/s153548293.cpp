#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 300010
long long mod = 998244353LL;
long long fac[MAXN], inv[MAXN];
long long power(long a, long x)
{
    long long ans = 1;
    while(x)
    {
        if(x&1)
        {
            ans  = ans * a % mod;
        }
        x >>= 1;
        a = a * a % mod;
    }
    return ans;
}
void init()
{
    fac[0] = 1;
    for(int i = 1; i < MAXN; i++)
        fac[i] = fac[i-1] * i % mod;
    inv[MAXN-1] = power(fac[MAXN-1], mod-2);
    for(int i = MAXN-2; i >= 0; i--)
        inv[i] = inv[i+1] * (i+1) % mod;
}
long long combinator(long long n,long long m)
{
    if(n < m)
        return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
    init();
    long long n, a, b, k, ans = 0;
    cin >> n >> a >> b >> k;
    for(int i = 0; i <= n; i++)
    {
        if(k - a*i < 0)
            continue;
        if((k-a*i) % b != 0)
            continue;
        long long y = (k-a*i)/b;
        if(y > n)
            continue;
        ans = (ans+combinator(n, i) * combinator(n, y) + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
