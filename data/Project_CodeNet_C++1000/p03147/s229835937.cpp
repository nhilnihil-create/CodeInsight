#include <iostream>
#include <vector>

int main()
{
    unsigned long long c = 0;
    int n; std::cin >> n;
    std::vector<int> h(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
        m = std::max(m, h[i]);
    }

    for (int i = 1; i <= m; i++) {
        bool b = false;
        for (int j = 0; j < n; j++) {
            if (h[j] >= i) {
                b = true;
            } else {
                if (b) {
                    c++;
                }
                b = false;
            }
        }
        if (b) {
            c++;
        }
    }

    std::cout << c << std::endl;
    return 0;
}
