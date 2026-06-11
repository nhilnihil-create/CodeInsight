#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> p;
    int d;
    dsu(int n) : p(n, -1) {d = n;}
    int find(int a) {
        if (p[a] < 0) return a;
        return p[a] = find(p[a]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        p[b] = a;
        d--;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        uf.unite(x, y);
    }
    cout << uf.d << endl;
    return 0;
}