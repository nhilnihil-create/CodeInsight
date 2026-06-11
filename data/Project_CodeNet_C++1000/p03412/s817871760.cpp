#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long n, m = 0;
    std::cin >> n;
    std::vector<long long> a(n), b(n);
    for (auto i = 0ll; i < n; i++) {
        std::cin >> a[i];
        if (m < a[i]) m = a[i];
    }
    for (auto i = 0ll; i < n; i++) {
        std::cin >> b[i];
    }

    auto ret = 0ll;
    for (auto i = 0ll; (1ll << i) <= m + b.back(); i++) {
        auto count = 0ll;
        auto s = 1ll << i;
        auto mod = s << 1ll;
        std::vector<long long> b2(n);
        for (auto j = 0ll; j < n; j++) b2[j] = (b[j] % mod);
        std::sort(b2.begin(), b2.end());
        for (auto c : a) {
            c = (c % mod);
            auto t = std::lower_bound(b2.begin(), b2.end(), s - c);
            auto t2 = std::upper_bound(b2.begin(), b2.end(), 2 * s - c - 1);
            auto t3 = std::lower_bound(b2.begin(), b2.end(), 3 * s - c);
            auto t4 = std::upper_bound(b2.begin(), b2.end(), 4 * s - c - 1);
            count += (t2 - t) + (t4 - t3);
        }
        if (count % 2 == 1) ret += (1ll << i);
    }

    std::cout << ret << std::endl;

    return 0;
}