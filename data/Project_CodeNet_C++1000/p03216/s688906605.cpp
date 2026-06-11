#include <bits/stdc++.h>
using i64 = long long;

int main() {
    i64 n, q;
    std::string s;
    std::cin >> n >> s >> q;
    std::vector<i64> b(n + 1), bc(n + 1), c(n + 1);
    for (int i = 0; i < s.size(); i++) {
        b[i + 1] = b[i] + (s[i] == 'M');
        c[i + 1] = c[i] + (s[i] == 'C');
        bc[i + 1] = bc[i] + (s[i] == 'C' ? b[i] : 0);
    }

    i64 k;
    for (; q--;) {
        std::cin >> k;
        i64 ret = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != 'D') continue;
            auto last = std::min(i + k, n);
            ret += bc[last] - bc[i + 1] - b[i + 1] * (c[last] - c[i + 1]);
        }
        std::cout << ret << std::endl;
    }

    return 0;
}