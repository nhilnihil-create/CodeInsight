#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    UnionFind(int n) : parent(n) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int root(int x){
        return x == parent[x] ? x : (parent[x] = root(parent[x])); // 経路圧縮
    }

    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx != ry) parent[rx] = parent[ry];
        return;
    }

    bool isSame(int x, int y){
        return root(x) == root(y);
    }
};


int main()
{
    int n, m, xi, yi, ans = 0;
    cin >> n >> m;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }

    UnionFind u(n);
    for(int i = 0; i < m; i++){
        cin >> xi >> yi;
        u.unite(xi - 1, yi - 1);
    }
    for(int i = 0; i < n; i++){
        if(u.isSame(i, p[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}