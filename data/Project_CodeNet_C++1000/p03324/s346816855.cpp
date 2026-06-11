#include <iostream>
#include <cmath>

int main()
{
    int d, n;
    std::cin >> d >> n;
    if (n == 100) {
        n = n + 1;
    }
    std::cout << static_cast<int>(n * pow(100, d)) << std::endl;

    return 0;
}