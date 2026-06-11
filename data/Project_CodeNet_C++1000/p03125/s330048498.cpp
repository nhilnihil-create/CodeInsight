#include <iostream>
#include <iomanip>

// std::cout << std::fixed << std::setprecision(5);

int main()
{
    int a, b;
    std::cin >> a >> b;
    if (b%a==0) std::cout << a + b << std::endl;
    else std::cout << b - a << std::endl;
    return 0;
}