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
    std::vector<long long> c(n), s(n), f(n);
    for (int i = 0; i < n - 1; i++) std::cin >> c[i] >> s[i] >> f[i];
    for (int t = 0; t < n; t++) {
        long long cur = 0;
        for (int i = t; i < n - 1; i++) {
            cur = std::max(s[i], (cur + f[i] - 1) / f[i] * f[i]) + c[i];
        }
        std::cout << cur << std::endl;
    }
    return 0;
}

