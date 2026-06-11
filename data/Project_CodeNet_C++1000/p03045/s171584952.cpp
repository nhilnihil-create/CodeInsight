#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

struct UnionFind
{
    vector<int> parent;
    UnionFind(int n) : parent(n) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int root(int x){
        return x == parent[x] ? x : (parent[x] = root(parent[x]));
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
    int n, m; cin >> n >> m;
    UnionFind u(n);
    int xi, yi, zi;
    rep(i, m){
        cin >> xi >> yi >> zi;
        --xi, --yi;
        u.unite(xi, yi);
    }

    int ans = 0;
    vector<bool> checked(n);
    rep(i, n){
        int ri = u.root(i);
        if(!checked[ri]){
            checked[ri] = true;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}