#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, a[maxn], fact[maxn], s[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = fact[0] = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        fact[i] = 1LL * i * fact[i - 1] % P;
        s[i] = (s[i - 1] + qp(i, P - 2)) % P;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + 1LL * a[i] * (s[i] + s[n - i + 1] - 1)) % P;
    }
    printf("%d\n", 1LL * fact[n] * ans % P);
    return 0;
}