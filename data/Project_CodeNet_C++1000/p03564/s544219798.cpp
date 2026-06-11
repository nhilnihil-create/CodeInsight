#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
    int n, k;
    std::cin >> n >> k;

    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = std::min(ans * 2, ans + k);
    }

    std::cout << ans << "\n";
}