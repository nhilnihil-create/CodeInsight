#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, z, w;
    std::cin >> n >> z >> w;

    std::vector< int > as(n);
    for (auto &a: as) std::cin >> a;

    int ans = abs(w - as.back());
    if (n > 2) ans = std::max(ans, abs(as[n - 2] - as[n - 1]));

    std::cout << ans << std::endl;
}

