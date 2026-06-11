#include <bits/stdc++.h>

template <class T>
T pow(T x, T n, T mod) {
    T ret = 1;
    while(n > 0) {
        if ((n & 1) == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

template <class T>
T inverse(T x, T p) { return pow(x, p - 2, p); }

int main() {
    long long n;
    const auto mod = 1000000007ll;
    std::cin >> n;
    std::vector<long long> a(n + 1);
    std::vector<long long> fact(n + 1), inv(n + 1);
    fact[0] = 1;
    for (auto i = 1ll; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = inverse(i, mod);
    }
    for (auto i = 1; i <= n; i++) inv[i] = (inv[i] + inv[i - 1]) % mod;

    for (int i = 1; i <= n; i++) std::cin >> a[i];

    std::vector<long long> s(n + 1);
    // s[1] = inv[n];
    // s[n] = inv[n];
    for (int i = 1; i <= n; i++) s[i] = (inv[i] + inv[n - i + 1] + mod - 1) % mod;
    auto ret = 0ll;
    for (int i = 1; i <= n; i++) {
        ret = (ret + s[i] * a[i] % mod * fact[n] % mod) % mod;
    }

    std::cout << ret << std::endl;

    return 0;
}