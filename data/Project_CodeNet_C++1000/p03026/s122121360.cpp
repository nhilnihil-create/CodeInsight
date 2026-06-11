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
    std::vector<std::vector<int>> edg(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; std::cin >> a >> b;
        a--; b--;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) std::cin >> c[i];
    std::sort(c.begin(), c.end());
    std::vector<int> ans(n, -1);
    std::vector<int> depth(n);
    auto dfs = [&](auto &self, int pos = 0, int prev = -1) -> void {
        for (int e : edg[pos]) {
            if (e == prev) continue;
            depth[e] = depth[pos] + 1;
            self(self, e, pos);
        }
    };
    dfs(dfs);
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
        return depth[i] > depth[j];
    });
    for (int i = 0; i < n; i++) {
        ans[id[i]] = c[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j : edg[i]) {
            sum += std::min(ans[i], ans[j]);
        }
    }
    std::cout << sum / 2 << std::endl;
    for (int i = 0; i < n; i++) std::cout << ans[i] << " \n"[i == n - 1];
    return 0;
}
