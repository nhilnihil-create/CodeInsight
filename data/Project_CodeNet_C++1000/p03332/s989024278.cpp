#include <iostream>
using namespace std;
constexpr int M = 998244353;
long long fact[300002], facti[300002];

int modinv(int a, int m) {
    int x = m, y = a, p = 1, q = 0, r = 0, s = 1;
    while (y != 0) {
        int u = x / y;
        int x0 = y; y = x - y * u; x = x0;
        int r0 = p - r * u, s0 = q - s * u;
        p = r; r = r0; q = s; s = s0;
    }
    return q < 0 ? q + m : q;
}

long long comb(int n, int k) {
    if (n < 0 || k < 0 || k > n) return 0;
    return fact[n] * facti[k] % M * facti[n-k] % M;
}

int main() {
    long long n, a, b, k; cin >> n >> a >> b >> k;
    fact[0] = 1; facti[0] = 1;
    for (int i = 1; i <= n+1; i++) {
        fact[i] = (fact[i-1] * i) % M;
        facti[i] = modinv(fact[i], M);
    }
    long long ans = 0;
    for (int p = 0; p <= n; p++) {
        // a*p + b*q = k
        if ((k - a*p) % b) continue;
        long long q = (k - a*p) / b;
        ans += comb(n, p) * comb(n, q) % M;
        if (ans >= M) ans -= M;
    }
    cout << ans << endl;
}
