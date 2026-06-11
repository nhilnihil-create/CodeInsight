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
    long long a, b; std::cin >> a >> b;
    long long ans = 0;
    auto func = [](long long u, long long t) {
        long long ret = u / (2 * t) * t;
        ret += std::max(0LL, u % (2 * t) - t + 1);
        return ret;
    };
    for (int i = 0; i < 60; i++) {
        long long t = 1LL << i;
        ans += t * ((func(b, t) - func(a - 1, t)) & 1);
    }
    std::cout << ans << std::endl;
    return 0;
}
