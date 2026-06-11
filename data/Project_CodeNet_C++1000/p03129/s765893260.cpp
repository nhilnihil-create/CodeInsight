#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;

    if ((n + 1) / 2 >= k) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
