#include <bits/stdc++.h>

int main() {
    long long n, x, ret = 1e18;
    std::cin >> n >> x;
    std::vector<long long> v(n + 1);
    for (auto i = 1ll; i <= n; i++) {
        std::cin >> v[i];
        v[i] += v[i - 1];
    }
    for (auto i = 1ll; i <= n; i++) {
        auto tmp = (n + i) * x;
        auto flg = true;
        for (auto j = 0; j <= n / i - (n % i == 0); j++) {
            tmp += (j ? (2 * j + 3) : 5) * (v[n - j * i] - v[std::max(0ll, n - (j + 1) * i)]);
            if (tmp > 1e18) {
                flg = false;
                break;
            }
        }
        if (flg) ret = std::min(ret, tmp);
    }

    std::cout << ret << std::endl;

    return 0;
}
