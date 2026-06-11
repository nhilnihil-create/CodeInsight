#include <bits/stdc++.h>

#define N 300010 

using namespace std;

typedef long long ll;

const int mod = 1000000007 ;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
    int x = 0, f = 1;
    char c = nc();
    while (c < 48) {
        if (c == '-')
            f = -1;
        c = nc();
    }
    while (c > 47) {
        x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
    }
    return x * f;
}

int a[N], fac[N], fac2[N], bfr[N];

int qpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) {
            ans = (ll)ans * x % mod;
        }
        y >>= 1;
        x = (ll)x * x % mod;
    }
    return ans;
}

int main() {
    int n = rd();
    for (int i = 1; i <= n; i ++ ) {
        a[i] = rd();
    }

    // init
    fac[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        fac[i] = (ll)fac[i - 1] * i % mod;
    }
    for (int i = 1; i <= n; i ++ ) {
        fac2[i] = (ll)fac[n] * qpow(i, mod - 2) % mod;
        bfr[i] = (bfr[i - 1] + fac2[i]) % mod;
    }

    // for (int i = 1; i <= n; i ++ ) {
    //     printf("%d ", fac[i]);
    // }
    // puts("");
    // for (int i = 1; i <= n; i ++ ) {
    //     printf("%d ", fac2[i]);
    // }
    // puts("");

    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        ans = (ans + (ll)a[i] * (
            (((ll)bfr[i] + bfr[n - i + 1]) % mod + mod - fac[n]) % mod
        )) % mod;
    }

    cout << ans << endl ;
    return 0;
}