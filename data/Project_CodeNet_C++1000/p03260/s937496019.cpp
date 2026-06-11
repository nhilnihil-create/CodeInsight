#include <iostream>

int main()
{
    int a, b; std::cin >> a >> b;
    std::cout << ((((a*b) % 2) == 1)?"Yes":"No") << std::endl;
    return 0;
}