#include <iostream>

int main() {
    int n, m, x; std::cin >> n >> m >> x;
    int r = 0;
    int l = 0;
    for (int i = 0; i < m; i++) {
        int a; std::cin >> a;
        ((a < x)?l:r) += 1;
    }
    std::cout << std::min(l, r) << std::endl;
    return 0;
}