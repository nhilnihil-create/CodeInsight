#include <iostream>
using namespace std;
constexpr int M = 998244353;

class ModComb {
    long long *fact, *facti;
    int mod;

    int modinv(int a) {
        int x = mod, y = a, p = 1, q = 0, r = 0, s = 1;
        while (y != 0) {
            int u = x / y;
            int x0 = y; y = x - y * u; x = x0;
            int r0 = p - r * u, s0 = q - s * u;
            p = r; r = r0; q = s; s = s0;
        }
        return q < 0 ? q + mod : q;
    }
public:
    explicit ModComb(int n, int m) : mod(m) {
        fact = new long long[n+1];
        facti = new long long[n+1];
        fact[0] = 1; facti[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i-1] * i) % m;
            facti[i] = modinv(fact[i]);
        }
    }

    long long get(int n, int k) {
        if (n < 0 || k < 0 || k > n) return 0;
        return fact[n] * facti[k] % M * facti[n-k] % M;
    }
};

int main() {
    long long n, a, b, k; cin >> n >> a >> b >> k;
    ModComb mc(n, M);
    long long ans = 0;
    for (int p = 0; p <= n; p++) {
        // a*p + b*q = k
        if ((k - a*p) % b) continue;
        long long q = (k - a*p) / b;
        ans += mc.get(n, p) * mc.get(n, q) % M;
        if (ans >= M) ans -= M;
    }
    cout << ans << endl;
}
