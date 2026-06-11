#include <iostream>

int main(){
    int tmp, a, b, c, d;
    std::cin >> tmp;

    d = tmp % 10;
    tmp = tmp / 10;
    c = tmp % 10;
    tmp = tmp / 10;
    b = tmp % 10;
    tmp = tmp / 10;
    a = tmp % 10;

    while (1)
    {
        if (a + b + c + d == 7)
        {
            std::cout << a << "+" << b << "+" << c << "+" << d << "=7" << std::endl;
            break;
        }
        if (a + b + c - d == 7)
        {
            std::cout << a << "+" << b << "+" << c << "-" << d << "=7" << std::endl;
            break;
        }
        if (a + b - c + d == 7)
        {
            std::cout << a << "+" << b << "-" << c << "+" << d << "=7" << std::endl;
            break;
        }
        if (a + b - c - d == 7)
        {
            std::cout << a << "+" << b << "-" << c << "-" << d << "=7" << std::endl;
            break;
        }
        if (a - b + c + d == 7)
        {
            std::cout << a << "-" << b << "+" << c << "+" << d << "=7" << std::endl;
            break;
        }
        if (a - b + c - d == 7)
        {
            std::cout << a << "-" << b << "+" << c << "-" << d << "=7" << std::endl;
            break;
        }
        if (a - b - c + d == 7)
        {
            std::cout << a << "-" << b << "-" << c << "+" << d << "=7" << std::endl;
            break;
        }
        if (a - b - c - d == 7)
        {
            std::cout << a << "-" << b << "-" << c << "-" << d << "=7" << std::endl;
            break;
        }
    }
    
    return 0;
}