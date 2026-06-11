#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        i64 a, b;
        std::cin >> a >> b;
        if (a < b) std::swap(a, b);
        if (a - b < 2) {
            std::cout << 2 * (b - 1) << std::endl;
            continue;
        }
        i64 s = a * b, l = 0, r = a;
        while (r - l > 1) {
            i64 k = (l + r) / 2;
            if (k * k < s) l = k;
            else r = k;
        }
        r = l;
        while (l * (r + 1) < s) r++;
        i64 ret = b - 1 + l + std::min(a - r, std::max(0ll, l - b - (l == r)));
        if (l - b > a - r) {
            for (int i = b + 1, j = r - 1; j > l && i <= l - (l == r) - a + r; i++) {
                if (i * j < s) {
                    ret++;
                    --j;
                }
            }
        }

        std::cout << ret << std::endl;
    }

    return 0;
}
