#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> num_bridges(4);

    for (int i = 0; i < 3; i++) {
        int a, b;
        std::cin >> a >> b;

        a--;
        b--;
        num_bridges[a]++;
        num_bridges[b]++;
    }

    for (auto elem : num_bridges) {
        if (elem > 2) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;
}
