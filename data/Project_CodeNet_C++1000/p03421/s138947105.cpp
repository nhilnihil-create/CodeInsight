#include <bits/stdc++.h>
using i64 = long long;

int main() {
    i64 n, a, b;
    std::cin >> n >> a >> b;
    if (n - a < b - 1 || a * (b - 1) < n - a) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::deque<i64> q { a };
    if (b - 1) {
        for (int i = 0; i < (n - a) % (b - 1); i++) q.push_back((n - a) / (b - 1) + 1);
        for (int i = (n - a) % (b - 1); i < b - 1; i++) q.push_back((n - a) / (b - 1));
    }
    i64 s = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < q[i]; j++) {
            std::cout << n - s - q[i] + 1 + j << " ";
        }
        s += q[i];
    }
    std::cout << std::endl;

    return 0;
}
