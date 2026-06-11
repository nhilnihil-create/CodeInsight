#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005, MOD = 1000000007; 
int n, a[N], pre[N], fac[N], ifac[N];

int qpow(int a, int b) {
    int res = 1;
    while (b) {if (b & 1) res = 1ll * res * a % MOD; a = 1LL * a * a % MOD; b >>= 1; }
    return res; 
}

int add(int a1, int b1) {
    a1 += b1;
    if (a1 >= MOD) a1 -= MOD;
    return a1; 
}
int main() {
    scanf("%d", &n);
    fac[0] = 1; 
    for (int i = 1; i <= n;i++) scanf ("%d", &a[i]), fac[i] = 1LL * fac[i - 1] * i % MOD;
    ifac[n] = qpow(fac[n], MOD - 2);
    for (int i = n-1; i >= 0; i--) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD; 
    for (int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + qpow(i, MOD - 2)) % MOD;
    LL ans = 0; 
    for (int i = 1; i <= n; i++) {
        int p1 = pre[i], p2 = pre[n - i + 1];
        ans = add(ans, 1LL * (p1 + p2 - 1) % MOD * a[i] % MOD);
    }

 //   cerr << ans << endl; 
    cout << ans * fac[n] % MOD << endl; 
    return 0; 
}