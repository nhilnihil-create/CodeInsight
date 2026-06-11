#include <iostream>

int main()
{
    int n, a; std::cin >> n >> a;
    int mod = n % 500;
    std::cout << (mod <= a ? "Yes" : "No") << std::endl;
}