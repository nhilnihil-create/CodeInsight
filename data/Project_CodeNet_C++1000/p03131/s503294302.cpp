#include <iostream>

int main()
{
    long long int k, a, b; std::cin >> k >> a >> b;
    if (b - a <= 2) {
        std::cout << (k + 1) << std::endl;
        return 0;
    }
    long long v = std::max(0LL, (k-a+1) / 2);
    std::cout << ((b-a) * (v) + (k - v * 2) + 1) << std::endl;
    return 0;
}
