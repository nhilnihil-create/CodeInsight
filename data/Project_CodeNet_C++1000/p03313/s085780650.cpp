#include <iostream>
#include <algorithm>
#include <vector>

using Int = long long int;
template <class T, class U>
using Pair = std::pair<T, U>;
template <class T>
using Vector = std::vector<T>;

struct Max2 {
    Vector<Pair<Int, Int>> idx;
    // a[i]とiのペア

    Max2& operator+=(const Max2& opp) {
        std::copy(opp.idx.begin(), opp.idx.end(),
                  std::back_inserter(idx));
        std::sort(idx.rbegin(), idx.rend());
        idx.erase(std::unique(idx.begin(), idx.end()), idx.end());
        idx.resize(2);
        return *this;
    }
};

int main() {
    Int n;
    std::cin >> n;
    Vector<Max2> g(1 << n);
    for (Int i = 0; i < (1 << n); ++i) {
        Int a;
        std::cin >> a;
        g[i].idx.emplace_back(a, i);
    }

    // 高速ゼータ変換 (下位集合ver)
    for (Int k = 0; k < n; ++k) {
        for (Int b = 0; b < (1 << n); ++b) {
            if ((b >> k) & 1) {
                g[b] += g[b ^ (1 << k)];
            }
        }
    }

    Int max = 0;
    for (Int b = 1; b < (1 << n); ++b) {
        max = std::max(max, g[b].idx[0].first + g[b].idx[1].first);
        std::cout << max << std::endl;
    }
    return 0;
}
