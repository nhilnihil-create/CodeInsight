#include <bits/stdc++.h>
int main() {
    int n, m; std::cin >> n >> m;
    int answ(1);
    auto update = [&](int g) {
        if (m / g >= n) answ = std::max(answ, g);
    };
    for (int i = 1; i * i <= m; i++) {
        int j = m / i;
        if (i * j == m) {
            update(i);
            update(j);
        }
    }
    std::cout << answ << std::endl;
}