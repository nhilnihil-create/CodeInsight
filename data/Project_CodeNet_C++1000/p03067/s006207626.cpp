#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a <= c && c <= b || a >= c && c >= b) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
