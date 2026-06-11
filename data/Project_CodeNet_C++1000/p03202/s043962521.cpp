#include <bits/stdc++.h>
using i64 = long long;

template <class T>
void print(T& v) {
    for (auto &p : v) std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    i64 l = 0, r = n + 1;
    while (r - l > 1) {
        auto k = (l + r) / 2;
        // { ケタ, 個数 }
        std::deque<std::pair<i64, i64>> q { { 0, 0 } };
        // std::cout << "k : " << k << std::endl;

        i64 prev = 10000000000;
        bool flg = true;
        for (int i = 1; i < n; i++) {
            // std::cout << i << std::endl;
            if (a[i] > a[i - 1]) continue;

            if (k == 1) {
                flg = false;
                break;
            }

            if (prev >= a[i]) {
                while (q.back().first > a[i]) q.pop_back();

                int curr = a[i];
                while (!q.empty() && q.back().first == curr && q.back().second == k - 1) {
                    q.pop_back();
                    curr--;
                }

                if (q.empty()) {
                    flg = false;
                    break;
                }

                if (q.back().first == curr) q.back().second++;
                else q.emplace_back(curr, 1);
            } else {
                q.emplace_back(a[i], 1);
            }
            // print(q);

            prev = a[i];
        }

        if (flg) r = k;
        else l = k;
    }

    std::cout << r << std::endl;

    return 0;
}