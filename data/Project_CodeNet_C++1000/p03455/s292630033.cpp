#include <iostream>

main()
{
    int a, b;
    std::cin >> a >> b;
    if(a%2==1 && b%2==1)
        std::cout << "Odd" << std::endl;
    else
        std::cout << "Even" << std::endl;
}