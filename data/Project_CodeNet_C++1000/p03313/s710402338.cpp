/* blog: https://misteer.hatenablog.com/entry/ARC100-E-zeta */

#include <iostream>
#include <algorithm>
#include <vector>

using Int = long long int;
template <class T>
using Vector = std::vector<T>;

struct G {
    Vector<Int> idx;
    static Vector<Int> a;

    G& operator+=(const G& opp) {
        std::copy(opp.idx.begin(), opp.idx.end(),
                  std::back_inserter(idx));
        std::sort(idx.begin(), idx.end(), [&](Int i, Int j) {
            return a[i] == a[j] ? i < j : a[i] > a[j];
        });
        idx.erase(std::unique(idx.begin(), idx.end()), idx.end());
        idx.resize(2);
        return *this;
    }
};
Vector<Int> G::a;

int main() {
    Int n;
    std::cin >> n;
    Vector<Int> a(1 << n);
    for (auto& x : a) std::cin >> x;
    G::a = a;

    Vector<G> g(1 << n);
    for (Int s = 0; s < (1 << n); ++s) {
        g[s].idx.push_back(s);
    }

    // 高速ゼータ変換 下位集合版
    for (Int k = 0; k < n; ++k) {
        for (Int b = 0; b < (1 << n); ++b) {
            if ((b >> k) & 1) {
                g[b] += g[b ^ (1 << k)];
            }
        }
    }

    Int max = 0;
    for (Int s = 1; s < (1 << n); ++s) {
        max = std::max(max, a[g[s].idx[0]] + a[g[s].idx[1]]);
        std::cout << max << std::endl;
    }
    return 0;
}
