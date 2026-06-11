#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int h, w, n, x, y;
    std::string s, t;
    std::cin >> h >> w >> n
        >> x >> y
        >> s >> t;

    // [lb, ub]
    std::vector<std::pair<int, int>> lr(2 * n + 1), ud(2 * n + 1);
    ud[2 * n] = std::make_pair(1, h);
    lr[2 * n] = std::make_pair(1, w);

    auto check = [&](int i) {
        if (lr[i].first > lr[i].second || ud[i].first > ud[i].second) {
            std::cout << "NO" << std::endl;
            exit(0);
        }
    };

    for (int i = n; i; i--) {
        if (t[i - 1] == 'D') {
            ud[2 * i - 1].first = std::max(1, ud[2 * i].first - 1);
            ud[2 * i - 1].second = ud[2 * i].second;
            lr[2 * i - 1] = lr[2 * i];
        } else if (t[i - 1] == 'U') {
            ud[2 * i - 1].first = ud[2 * i].first;
            ud[2 * i - 1].second = std::min(h, ud[2 * i].second + 1);
            lr[2 * i - 1] = lr[2 * i];
        } else if (t[i - 1] == 'R') {
            lr[2 * i - 1].first = std::max(1, lr[2 * i].first - 1);
            lr[2 * i - 1].second = lr[2 * i].second;
            ud[2 * i - 1] = ud[2 * i];
        } else if (t[i - 1] == 'L') {
            lr[2 * i - 1].first = lr[2 * i].first;
            lr[2 * i - 1].second = std::min(w, lr[2 * i].second + 1);
            ud[2 * i - 1] = ud[2 * i];
        }

        if (s[i - 1] == 'D') {
            ud[2 * i - 2].first = ud[2 * i - 1].first;
            ud[2 * i - 2].second = ud[2 * i - 1].second - 1;
            lr[2 * i - 2] = lr[2 * i - 1];
        } else if (s[i - 1] == 'U') {
            ud[2 * i - 2].first = ud[2 * i - 1].first + 1;
            ud[2 * i - 2].second = ud[2 * i - 1].second;
            lr[2 * i - 2] = lr[2 * i - 1];
        } else if (s[i - 1] == 'R') {
            lr[2 * i - 2].first = lr[2 * i - 1].first;
            lr[2 * i - 2].second = lr[2 * i - 1].second - 1;
            ud[2 * i - 2] = ud[2 * i - 1];
        } else if (s[i - 1] == 'L') {
            lr[2 * i - 2].first = lr[2 * i - 1].first + 1;
            lr[2 * i - 2].second = lr[2 * i - 1].second;
            ud[2 * i - 2] = ud[2 * i - 1];
        }

        check(2 * i - 2);
    }

    bool flg = ud[0].first <= x && x <= ud[0].second && lr[0].first <= y && y <= lr[0].second;
    std::cout << (flg ? "YES" : "NO") << std::endl;

    return 0;
}
