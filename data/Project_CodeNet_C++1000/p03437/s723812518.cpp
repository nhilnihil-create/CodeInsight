#include <iostream>

int main()
{
    long long x, y;
    std::cin >> x >> y;

    if (x % y == 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::cout << x * (y - 1) << std::endl;
}
