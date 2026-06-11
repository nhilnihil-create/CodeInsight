#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((ll)((a) + (b) - 1)/(ll)(b))

struct UnionFind {
    vector<int> par, treesize;
    int groups;
    
    UnionFind(int n){
        rep(i, n) par.push_back(i);
        treesize = vector<int>(n,1);
        groups = n;
    }
    
    int root(int x){
        if(x == par.at(x)) return x;
        return par.at(x) = root(par.at(x));
    }
    
    bool same(int x, int y){
        return root(x) == root(y);
    }
    
    void unite(int x, int y){
        if(same(x,y)) return;
        int rx = root(x), ry = root(y);
        treesize[ry] += treesize[rx];
        treesize[rx] = 0;
        groups--;
        par.at(rx) = ry;
    }
    
    int get_size(int x){
        return treesize[root(x)];
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        uf.unite(x, y);
    }
    cout << uf.groups << endl;
}