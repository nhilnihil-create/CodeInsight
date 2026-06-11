#include <iostream>
#include <functional>
using namespace std;

const long long MOD = 998244353;

int main() {
    long long n, a, b, k, result = 0;
    cin >> n >> a >> b >> k;
    long long factorial[n + 1], inv[n + 1], ifactorial[n + 1];
    factorial[0] = 1;
    ifactorial[0] = 1;
    factorial[1] = 1;
    ifactorial[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i % MOD;
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        ifactorial[i] = inv[i] * ifactorial[i - 1] % MOD;
    }
    function<long long(long long, long long)> C = [&](long long n, long long k) {
        return factorial[n] * ifactorial[k] % MOD * ifactorial[n - k] % MOD;
    };
    for (long long i = 0; i <= n && i * a <= k; i++) {
        if ((k - i * a) % b == 0) {
            long long j = (k - i * a) / b;
            if (j <= n) {
                result = (result + C(n, i) * C(n, j)) % MOD;
            }
        }
    }
    cout << result;
    return 0;
}