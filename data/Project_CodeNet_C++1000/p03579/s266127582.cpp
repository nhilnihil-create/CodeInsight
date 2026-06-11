#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

//---------------------------------------------------------------
// ------ disjoint set ------ //
struct UnionFind {
    vector<int> data;
    int __size;
    UnionFind(int size) : data(size, -1), __size(size) { }
    bool unionSet(int x, int y) {
        if ((x = root(x)) != (y = root(y))) {
            if (data[y] < data[x]) swap(x, y);  // par -> child とは限らない
            data[x] += data[y]; data[y] = x; __size--;
        }
        return x != y;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
    int size() { return __size; }
    vector<int> subset_roots() {
        vector<int> roots;
        for (int i = 0; i < data.size(); i++) if (data[i] < 0) roots.push_back(i);
        return roots;
    }
};
//---------------------------------------------------------------

int main() {
    int n, m; cin >> n >> m;
    UnionFind uf(n * 2);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        uf.unionSet(a, b + n);
        uf.unionSet(a + n, b);
    }
    if (uf.findSet(0, n)) {
        cout << 1LL * n * (n - 1) / 2 - m << endl;
    } else {
        int cnt = 0;
        for (int i = 0; i < n; i++) if (uf.findSet(0, i)) cnt++;
        cout << 1LL * cnt * (n - cnt) - m << endl;
    }
    return 0;
}