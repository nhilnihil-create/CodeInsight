#include <iostream>
#include <vector>
#include <stack>

int main() {
    int n; std::cin >> n;
    std::vector<std::vector<std::pair<int /* to */, int /* cols */>>> e(n);
    for (int i = 0; i < n-1; i++) {
        int u, v, w; std::cin >> u >> v >> w; u--; v--;
        e[u].push_back(std::make_pair(v, w));
        e[v].push_back(std::make_pair(u, w));
    }
    std::vector<int> c(n, -1);
    std::stack<int> s;
    s.push(0); c[0] = 0;
    while (!s.empty()) {
        int v = s.top(); s.pop();
        // std::cout << v << std::endl;
        for (const auto ee: e[v]) {
            if (c[ee.first] != -1) {
                continue;
            }
            // std::cout << "    " << ee.first << std::endl;
            if (ee.second % 2 == 0) {
                c[ee.first] = c[v];
            } else {
                c[ee.first] = 1 - c[v];
            }
            s.push(ee.first);
        }
    }
    for (int i = 0; i < n; i ++) {
        std::cout << c[i] << std::endl;
    }
    return 0;
}