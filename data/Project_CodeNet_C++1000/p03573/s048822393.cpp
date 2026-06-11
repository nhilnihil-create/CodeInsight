#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int d = (a==b)?c:(a==c?b:a);
    std::cout << d << std::endl;
    return 0;
}