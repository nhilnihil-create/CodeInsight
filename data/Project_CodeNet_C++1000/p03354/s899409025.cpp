#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par, s;

    UnionFind(int n) : par(n), s(n, 1) {
        for(int i = 0; i < n; i++) par[i] = i;
    }

    int root(int n) {
        return par[n] == n ? n : root(par[n]);
    }

    void unite(int n, int m) {
        n = root(n);
        m = root(m);
        if (n == m) return;
        if (s[n] < s[m]) swap(n, m);
        s[n] += s[m];
        par[m] = n;
    }

    int size(int n) {
        return s[root(n)];
    }

    bool same(int n, int m) {
        return root(n) == root(m);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for(auto& e : p){
        cin >> e;
        e--;
    }
    UnionFind un(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y, x--, y--;
        un.unite(x, y);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if(un.same(i, p[i])) cnt++;
    }
    cout << cnt << endl;
    return 0;
}