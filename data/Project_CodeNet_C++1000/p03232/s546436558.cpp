#include <bits/stdc++.h>
#define MAX_N 100007
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N;
ll a[MAX_N], b[MAX_N];
ll inv[MAX_N], sum[MAX_N], res;

inline void init () {
    inv[0] = inv[1] = 1;
    for (int i = 2;i <= N; ++i)
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    for (int i = 1;i <= N; ++i)
        sum[i] = sum[i - 1] + inv[i];
}

int main () {
    scanf("%d", &N);
    for (int i = 1;i <= N; ++i)
        scanf("%d", a + i);
    init();
    for (int i = 1;i <= N; ++i)
        b[i] = (sum[N - i + 1] - 1 + sum[i] + MOD) % MOD;
    for (int i = 1;i <= N; ++i)
        (res += a[i] * b[i]) %= MOD;
    for (int i = 2;i <= N; ++i)
        res = res * i % MOD;
    printf("%lld\n", res % MOD);
    return 0;
}
