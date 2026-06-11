#include <iostream>
#include <vector>

int main() {
    int a, b; std::cin >> a >> b;

    std::cout << std::max(a+b, std::max(a-b, a*b)) << std::endl;
    return 0;
}