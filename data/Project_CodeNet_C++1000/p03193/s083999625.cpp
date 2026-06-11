#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int n, h, w;
    std::cin >> n >> h >> w;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;

        if (a >= h && b >= w) {
            count++;
        }
    }

    std::cout << count << std::endl;
}
