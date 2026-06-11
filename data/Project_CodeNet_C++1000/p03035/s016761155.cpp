#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;

    if (13 <= a)
    {
        std::cout << b << std::endl;
    }
    else if (6 <= a && a <=12)
    {
        std::cout << b / 2 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    
    return 0;
}