#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int a, b;
    std::cin >> a >> b;

    if (a + b == 15) {
        std::cout << "+" << std::endl;
    } else if (a * b == 15) {
        std::cout << "*" << std::endl;
    } else {
        std::cout << "x" << std::endl;
    }
}
