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
    std::vector<int> w(n), s(n), v(n);
    for (int i = 0; i < n; i++) std::cin >> w[i] >> s[i] >> v[i];
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
        return w[i] + s[i] < w[j] + s[j];
    });
    std::vector<long long> dp(1e5, -1e18);
    dp[0] = 0;
    for (int i : id) {
        for (int j = s[i]; j >= 0; j--) {
            dp[j + w[i]] = std::max(dp[j + w[i]], dp[j] + v[i]);
        }
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
    return 0;
}
