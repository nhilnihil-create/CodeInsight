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
    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }
    long long sum = std::accumulate(a.begin(), a.end(), 0LL);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) continue;
        ans = std::max(ans, sum - b[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}
