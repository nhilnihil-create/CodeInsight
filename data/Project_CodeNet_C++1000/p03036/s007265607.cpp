#include <iostream>


int main() {
    int r, D, x;
    std::cin >> r >> D >> x;
    for (int i = 0; i < 10; i++) {
        x = r * x - D;
        std::cout << x << std::endl;
    }
}
