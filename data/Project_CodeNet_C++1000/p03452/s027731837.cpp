#include <iostream>
#include <vector>

using namespace std;

struct potential_union_find{
    vector<int> par, sz, diff_w;

    potential_union_find(int n) {
        par.resize(n);
        sz.resize(n);
        diff_w.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 0; 
            diff_w[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x)
            return x;
        else {
            int r = find(par[x]);
            diff_w[x] += diff_w[par[x]];
            return par[x] = r;
        }
    }

    int weight(int x) {
        find(x);
        return diff_w[x];
    }

    bool unite(int x, int y, int w) {
        w += weight(x); w -= weight(y);

        x = find(x), y = find(y);

        if (x == y)
            return false;
    
        if (sz[x] < sz[y]) {
            swap(x, y);
            w = -w;
        }

        if (sz[x] ==  sz[y])
            sz[x]++;
        par[y] = x;
        diff_w[y] = w;
        return true;
    }

    int diff(int x, int y) {
        return weight(y) - weight(x);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, m;   cin >> n >> m;
    potential_union_find u(n);
    bool can = true;
    for (int i = 0; i < m; i++) {
        int r, l, d;    cin >> r >> l >> d;
        l--, r--;

        if (!u.same(r, l)) {
            u.unite(r, l, d);
        }
        else {
            if (u.diff(r, l) != d) {
                can = false;
            }
        }
    }
    if (can)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}