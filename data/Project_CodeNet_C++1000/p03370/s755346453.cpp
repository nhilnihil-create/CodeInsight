#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, x; std::cin >> n >> x;
    std::vector<int> m(n);

    int min = 10000;
    int sum = 0;
    int ans = n;
    for(int i = 0;i < n; i++) {
        std::cin >> m[i];
        sum += m[i];
        min = std::min(min, m[i]);
    }

    ans += (x - sum)/min;

    std::cout << ans << std::endl;
}