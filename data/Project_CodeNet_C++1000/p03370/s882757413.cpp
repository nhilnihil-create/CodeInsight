#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
int main()
{
    int N, X;
    std::vector<int> m;
    std::cin >> N >> X;
    int tmp;
    for (int a = 0; a < N; a++) {
        std::cin >> tmp;
        m.push_back(tmp);
        X -= tmp;
    }
    std::cout << X / *std::min_element(m.begin(), m.end()) + N << std::endl;
}