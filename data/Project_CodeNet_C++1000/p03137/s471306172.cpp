#include <iostream>
#include <vector>

int main()
{
    int n, m; std::cin >> n >> m;
    std::vector<int> x(m);
    for (int i = 0; i < m; i++) {
        std::cin >> x[i];
    }
    if (n >= m) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::sort(x.begin(), x.end());

    int td = x.back() - x.front();

    std::vector<int> d(m-1);
    for (int i = 1; i < m; i++) {
        d.push_back(std::abs(x[i-1] - x[i]));
    }
    std::sort(d.begin(), d.end(), std::greater<int>());

    for (int i = 0; i < n-1; i++) {
        td -= d[i];
    }

    std::cout << td << std::endl;

    return 0;
}
