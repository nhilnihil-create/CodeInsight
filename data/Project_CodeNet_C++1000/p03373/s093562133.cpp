#include <iostream>
#include <cstdlib>

int main() {
    int32_t a, b, c, x, y;
    std::cin >> a >> b >> c >> x >> y;
    
    int32_t cost = 0;
    
    if (a + b <= 2 * c) {
        cost = a * x + b * y;
    } else {
        int32_t a_or_b = ((x > y) ? a : b);
        if (a_or_b > 2 * c) {
            cost = 2 * c * std::max(x, y);
        } else {
            int32_t min = std::min(x, y);
            cost += 2 * c * min;
            int32_t left = std::max(x, y) - min;
            cost += a_or_b * left;
        }
    }

    std::cout << cost << std::endl;
    
    return 0;
}