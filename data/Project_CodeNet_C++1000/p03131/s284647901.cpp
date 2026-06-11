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
    long long k, a, b; std::cin >> k >> a >> b;
    if (k <= a - 1) {
        std::cout << k + 1 << std::endl;
        return 0;
    }
    long long ans = a;
    k -= a - 1;
    ans += k/2*std::max(2LL, b - a);
    ans += k & 1;
    std::cout << ans << std::endl;
    return 0;
}
