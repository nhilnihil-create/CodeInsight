#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n{}, m{};
    std::cin >> n >> m;
    std::vector<int> l(m);
    std::vector<int> r(m);
    for (int i = 0; i < m; i++) {
        std::cin >> l[i] >> r[i];
    }
    const auto minR = *std::min_element(r.begin(), r.end());
    const auto maxL = *std::max_element(l.begin(), l.end());
    std::cout << std::max(0, minR - maxL + 1);
    return 0;
}