#include <bits/stdc++.h>
using i64 = long long;

int main() {
    int h, w, n, x, y;
    std::string s, t;
    std::cin >> h >> w >> n
        >> x >> y
        >> s >> t;

    // [lb, ub]
    auto ud = std::make_pair(1, h), lr = std::make_pair(1, w);

    for (int i = n; i; i--) {
        if (t[i - 1] == 'D') ud.first = std::max(1, ud.first - 1);
        else if (t[i - 1] == 'U') ud.second = std::min(h, ud.second + 1);
        else if (t[i - 1] == 'R') lr.first = std::max(1, lr.first - 1);
        else if (t[i - 1] == 'L') lr.second = std::min(w, lr.second + 1);

        if (s[i - 1] == 'D') --ud.second;
        else if (s[i - 1] == 'U') ++ud.first;
        else if (s[i - 1] == 'R') --lr.second;
        else if (s[i - 1] == 'L') ++lr.first;

        if (lr.first > lr.second || ud.first > ud.second) break;
    }

    bool flg = ud.first <= x && x <= ud.second && lr.first <= y && y <= lr.second;
    std::cout << (flg ? "YES" : "NO") << std::endl;

    return 0;
}
