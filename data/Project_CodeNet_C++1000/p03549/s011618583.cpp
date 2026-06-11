#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int ans = 1900 * m + (n - m) * 100;
    for (int i = 0; i < m; ++i) {
        ans *= 2;
    }

    std::cout << ans << std::endl;
}
