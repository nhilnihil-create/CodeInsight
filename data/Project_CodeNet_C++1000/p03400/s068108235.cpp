#include <iostream>

int main() {
    int n, d, x; std::cin >> n >> d >> x;
    d--;
    for (int i = 0; i < n; i++) {
        int v; std::cin >> v;
        x += 1 + (d / v);
    }
    std::cout << x << std::endl;
    return 0;
}