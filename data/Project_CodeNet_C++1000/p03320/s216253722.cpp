#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int k;
    std::cin >> k;

    auto f = [](const auto n) {
        auto m = n, s = 0ll;
        while (m) {
            s += m % 10;
            m /= 10;
        }
        return 1.0 * n / s;
    };

    std::vector<i64> ret { 1 };
    while (ret.size() < k) {
        auto lst = ret.back() + 1;
        double min = f(lst);
        i64 cand = lst;
        for (i64 c = 10, j = 0; j < 16; c *= 10, j++) {
            i64 x = (lst / c + 1) * c - 1;
            auto v = f(x);
            if (v < min) {
                cand = x;
                min = v;
            }
        }
        ret.push_back(cand);
    }

    for (auto e : ret) std::cout << e << std::endl;

    return 0;
}
