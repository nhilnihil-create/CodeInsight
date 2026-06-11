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
    int n, k; std::cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) std::cin >> v[i];
    std::vector<int> buf;
    int ans = 0;
    for (int t = 1; t <= k; t++) {
        for (int i = 0; i <= t; i++) {
            int j = n - t + i - 1;
            if (j < i) continue;
            buf.clear();
            for (int b = 0; b < i; b++) buf.push_back(v[b]);
            for (int b = n - 1; b > j; b--) buf.push_back(v[b]);
            int s = std::accumulate(buf.begin(), buf.end(), 0);
            std::sort(buf.begin(), buf.end());
            for (int b = 0; b < std::min(t, k - t); b++) {
                if (buf[b] >= 0) break;
                s -= buf[b];
            }
            ans = std::max(ans, s);
        }
    }
    if (k >= n) {
        int s = std::accumulate(v.begin(), v.end(), 0);
        for (int b = 0; b < std::min(n, k - n); b++) {
            if (v[b] >= 0) break;
            s -= v[b];
        }
        ans = std::max(ans, s);
    }
    std::cout << ans << std::endl;
    return 0;
}