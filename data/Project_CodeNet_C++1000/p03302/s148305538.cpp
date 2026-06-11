#include <iostream>
int main() {
    int a, b;
    std::cin >> a >> b;
    if (a + b == 15)
        puts("+");
    else if (a * b == 15)
        puts("*");
    else
        puts("x");
}