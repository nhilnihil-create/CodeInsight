#include <bits/stdc++.h>
using i64 = long long;

std::vector<std::deque<int>> g;

std::pair<int, int> dfs(int v, int p) {
    std::pair<int, int> ret { v, 0 };
    for (auto c : g[v]) {
        if (c == p) continue;
        const auto q = dfs(c, v);
        if (q.second + 1 > ret.second) {
            ret.second = q.second + 1;
            ret.first = q.first;
        }
    }
    return ret;
}

int main() {
    int n;
    std::cin >> n;
    g.resize(n);
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto d = dfs(dfs(0, -1).first, -1).second;
    std::cout << (d % 3 != 1 ? "First" : "Second") << std::endl;

    return 0;
}
