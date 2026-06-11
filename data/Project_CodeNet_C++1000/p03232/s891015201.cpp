#include <bits/stdc++.h>

typedef long long int int64;
static const int64 mod = 1000000007LL;
int64 inv[100003],fac[100003],invfac[100003];
int64 x[100003];

int n;
int64 v[100003];
int main()
{
    scanf("%d",&n);
    int64 base = 1;
    inv[1] = 1;
    for(int i = 2;i <= n;++i) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        base = base * i % mod;
    }
    for(int i = 1;i <= n;++i) {
        x[i] = (x[i - 1] + base * inv[i]) % mod;
    }
    int64 ans = 0;
    for(int i = 0;i < n;++i) {
        scanf("%lld",&v[i]);
        int64 k = v[i] * (x[i + 1] + x[n - i] - base) % mod;
        ans = ans + k;
    }
    ans = ans % mod;
    if(ans < 0) ans += mod;
    printf("%lld\n", ans % mod);
}
