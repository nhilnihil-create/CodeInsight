#include <iostream>
#include <vector>
#include <set>

class uft {
public:
    uft(int n) {
        v = std::vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
    }

    int root(int i) {
        if (v[i] == i) {
            return i;
        }
        return v[i] = root(v[i]);
    }

    void unite(int i, int j) {
        int ii = root(i);
        int jj = root(j);
        if (ii != jj) {
            v[ii] = jj;
        }
    }

    bool same(int i, int j) {
        return root(i) == root(j);
    }

private:
    std::vector<int> v;
};

int main() {
    int n, m; std::cin >> n >> m;
    uft u(n);
    for (int i = 0; i < m; i++) {
        int x, y, z; std::cin >> x >> y >> z;
        x--; y--;
        u.unite(x, y);
    }

    int ret = 0;
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        int v = u.root(i);
        if (s.find(v) == s.end()) {
            ret++;
        }
        s.insert(v);
    }
    std::cout << ret << std::endl;
    return 0;
}