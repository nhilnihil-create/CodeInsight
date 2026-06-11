#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int h, w, n;
    std::cin >> h >> w >> n;
    std::vector<std::set<int>> vv(h + 1);
    std::set<std::pair<int, int>> bl;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        vv[x].insert(y);
        bl.emplace(x, y);
    }

    int p = 1;
    int q = 1;
    while (p < h) {
        auto it = vv[p + 1].upper_bound(q);
        if (it != vv[p + 1].begin() && *(--it) <= q) break;

        p++;
        if (bl.find({ p, q + 1 }) == bl.end()) q++;
        // std::cout << p << " " << q << std::endl;
    }

    std::cout << p << std::endl;

    return 0;
}