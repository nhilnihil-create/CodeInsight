#include <iostream>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;

/**
 *
 *
 * 考虑把绿色视为红色加蓝色
 * 那么题目就转化成了给每一层涂两种颜色，可以全涂红色（贡献为 A）、蓝色（贡献为 B）、涂红色和蓝色（贡献为 C = A + B）、不涂颜色（贡献为 0）
 * 设 a 层涂了红色，b 层涂了蓝色，则答案为 sum{ C(a, N) * C(b, N) | (0 <= a, b <= N, A * a + B * b = K) }
 *
 */

const int MAXN = 3 * 1e6 + 10;
const int HA = 998244353;

long long int fac[MAXN], inv[MAXN], N, A, B, K;

long long int fastPow(long long int a, long long int b) {
    if (b == 0) return 1;
    if (b == 1) return a % HA;
    long long int ret = 1;
    while (b) {
        if (b & 1) ret = (ret * a) % HA;
        a = a * a % HA;
        b >>= 1;
    }
    return ret;
}

long long int C(long long int m, long long int n) {
    return fac[n] * inv[m] % HA * inv[n - m] % HA;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> N >> A >> B >> K;
    fac[0] = 1; inv[0] = 1;
    for (long long int i = 1; i <= N; ++i) {
        fac[i] = fac[i - 1] * i % HA;
        inv[i] = fastPow(fac[i], HA - 2);
    }
    long long int ans = 0;
    for (long long int a = 0; a <= N; ++a) {
        // A * a + B * b = K
        //cout << "((K - A * a) % B + B) % B = " << ((K - A * a) % B + B) % B << endl;
        if (((K - A * a) % B + B) % B != 0) continue;
        long long int b = (K - A * a) / B;
        (ans += (C(a, N) * C(b, N)) % HA) %= HA;
    }
    cout << ans << endl;
    return 0;
}