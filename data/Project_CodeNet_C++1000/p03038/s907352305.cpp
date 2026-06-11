#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Operation {
    int64_t b{};
    int64_t c{};
};

int main() {
    int n{}, m{};
    std::cin >> n >> m;
    std::vector<int64_t> a(n);
    std::vector<Operation> op(m);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    for (int i = 0; i < m; i++) std::cin >> op[i].b >> op[i].c;
    std::sort(a.begin(), a.end());
    std::sort(op.begin(), op.end(), [](const auto& x, const auto& y) {
        return x.c > y.c;
    });
    int a_i = 0;
    int op_i = 0;
    while (a_i < n && op_i < m && op[op_i].c > a[a_i]) {
        a[a_i] = op[op_i].c;
        op[op_i].b--;
        if (op[op_i].b == 0) op_i++;
        a_i++;
    }
    std::cout << std::accumulate(a.begin(), a.end(), 0LL) << std::endl;
}