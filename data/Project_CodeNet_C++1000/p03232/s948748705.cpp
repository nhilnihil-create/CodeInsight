#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
const int mod = 1e9+7;

typedef long long ll;

int n  = 0;
int A[maxn];
int jc[maxn], ijc[maxn], inv[maxn];
int sum[maxn], val[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = 1ll*(mod/i)*(mod-inv[mod%i])%mod;
    }
    jc[0] = ijc[0] = 1;
    for (int i = 1; i <= n; i++) {
        jc[i] = 1ll*jc[i-1]*i%mod;
        ijc[i] = 1ll*ijc[i-1]*inv[i]%mod;
    }
    for (int i = 1; i <= n; i++)
        val[i] = 1ll*jc[n]*inv[i]%mod;
    val[1] = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = (sum[i-1]+val[i])%mod;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l1 = i, l2 = n-i+1;
        if (l1 > l2) swap(l1, l2);
        (ans += (((2ll*sum[l1]%mod)%mod+sum[l2]-sum[l1])%mod+mod)%mod*A[i]%mod)%=mod;
    }
    for (int i = 1; i <= n; i++) ans = (ans + 1ll*A[i]*jc[n]%mod)%mod;
    printf("%d\n", ans);
    return 0;
}
