#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

struct UnionFind {
    vector<int> data;

    UnionFind(int size) : data(size, -1) {}
    void unite(int x, int y) {
        auto rx = root(x);
        auto ry = root(y);
        if (rx == ry)
            return;

        auto x_size = -data[rx];
        auto y_size = -data[ry];
        if (x_size > y_size) {
            data[rx] = ry;
            data[ry] = -(x_size + y_size);
        } else {
            data[ry] = rx;
            data[rx] = -(x_size + y_size);
        }
    }

    int root(int x) {
        if (data[x] < 0)
            return x;
        data[x] = root(data[x]);
        return data[x];
    }
};

int main() {
    int n, m; // 100'000;
    cin >> n >> m;

    auto uf = UnionFind(n);
    for (auto i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x, --y;
        uf.unite(x, y);
    }

    auto group_count = 0;
    auto remains = n;
    for (auto i = 0; i < n; ++i) {
        if (uf.root(i) == i) {
            group_count++;
            remains -= -(uf.data[i]);
        }
    }

    cout << group_count + remains << endl;
    return 0;
}
