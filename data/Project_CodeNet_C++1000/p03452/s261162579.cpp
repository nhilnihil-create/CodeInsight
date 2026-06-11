#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

int par[MAX_N + 1], ds[MAX_N + 1];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        ds[i] = 0;
    }
}

int find(int x) {
    if (par[x] == x)
        return x;
    int px = par[x];
    par[x] = find(par[x]);
    ds[x] += ds[px];
    return par[x];
}

bool unite(int _x, int _y, int d) {
    int x = find(_x), y = find(_y);
    if (x == y) {
        if (ds[_y] - ds[_x] != d)
            return false;
    } else {
        par[y] = x;
        ds[y] = d - ds[_y] + ds[_x];
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        if (!unite(l, r, d)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

