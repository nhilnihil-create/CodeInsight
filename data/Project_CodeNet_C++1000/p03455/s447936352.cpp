#include <iostream>
#include <string>

int main()
{
    uint16_t a = 0, b = 0;

    std::cin >> a >> b;
    std::string s = ((a * b) % 2 == 0) ? "Even" : "Odd";
    std::cout << s << std::endl;

    return 0;
}