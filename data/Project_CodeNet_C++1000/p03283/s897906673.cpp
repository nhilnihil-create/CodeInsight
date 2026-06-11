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
    int n, m, q; std::cin >> n >> m >> q;
    std::vector<std::vector<int>> cnt(n + 2, std::vector<int>(n + 2));
    for (int i = 0; i < m; i++) {
        int a, b; std::cin >> a >> b;
        cnt[b][a]++;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cnt[i + 1][j] += cnt[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cnt[i][j + 1] += cnt[i][j];
        }
    }
    while (q--) {
        int a, b; std::cin >> a >> b;
        std::cout << cnt[b][n] - cnt[b][a - 1] << std::endl;
    }
    return 0;
}
