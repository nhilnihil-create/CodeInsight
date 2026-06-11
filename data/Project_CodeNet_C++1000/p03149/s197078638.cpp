#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> n(4);
    for (int i = 0; i < 4; i++) {
        std::cin >> n[i];
    }

    std::sort(n.begin(), n.end());

    std::vector<int> right = { 1, 4, 7, 9 };

    if (n == right) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
