#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <iomanip>
#include <cassert>
#include <random>


int main() {
    int n; std::cin >> n;
    std::vector<int> c(n), s(n), f(n);
    for (int i = 0; i < n - 1; i++) std::cin >> c[i] >> s[i] >> f[i];
    for (int start = 0; start < n; start++) {
        int ans = 0;
        for (int pos = start; pos < n - 1; pos++) {
            int t = std::max(s[pos], (ans + f[pos] - 1) / f[pos] * f[pos]);
            ans = t + c[pos];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
