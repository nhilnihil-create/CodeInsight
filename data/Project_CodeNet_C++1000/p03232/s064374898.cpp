#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
long long fac[maxn];
long long inv[maxn];
void pre()
{
    fac[0] = 1;
    inv[0] = 1;
    inv[1] = 1;
    fac[1] = 1;
    for(int i=2; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - (mod / i * inv[mod % i]) % mod;
    }
//    for(int i=2; i< maxn; i++)
//        inv[i] = inv[i - 1] * inv[i] % mod;
}
int a[maxn];
int main()
{
    int n;
    pre();
    scanf("%d",&n);
    long long sum = 0;
    for(int i=1; i <= n; i++)
    {
        int x;
        scanf("%d", a + i);
        sum = sum + a[i];
        if(sum >= mod) sum -= mod;
    }
    long long ans = sum * fac[n] % mod;
    sum = 0;
    for(int i=1; i <= n; i++)
    {
        ans = (ans + sum * a[i]) % mod;
        sum = (sum + fac[n] * inv[i + 1]) % mod;
    }
    sum = 0;
    for(int i=n; i >= 1; i--)
    {
        ans = (ans + sum * a[i]) % mod;
        sum = (sum + fac[n] * inv[n - i + 2]) % mod;
    }
    printf("%lld\n",ans % mod);
    return 0;
}
