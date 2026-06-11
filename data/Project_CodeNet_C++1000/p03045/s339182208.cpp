#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

struct UnionFind{
    vector<long long> par;
    vector<long long> size;

    UnionFind(long long n) : par(n){
        //initialization
        for(long long i = 0; i < n; i++){
            par[i] = i;
        }
        size.resize(n, 1);
    }

    long long root(long long x){
        if(par[x] == x){
            return x;
        }
        return par[x] = root(par[x]);
    }

    void unite(long long x, long long y){
        long long rx = root(x);
        long long ry = root(y);
        if(rx == ry){
            return;
        }

        par[rx] = ry;
        size[ry] += size[rx]; 
    }

    bool same(long long x, long long y){
        long long rx = root(x);
        long long ry = root(y);
        return rx == ry;
    }

    long long treeSize(long long x){
        //group size
        return size[root(x)];
    }
};

int main(){
    long long n, m;
    cin >> n >> m;

    UnionFind tree(n);

    for(long long i = 0; i < m; i++){
        long long x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        tree.unite(x, y);
    }

    set<long long> T;

    for(long long i = 0; i < n; i++){
        T.insert(tree.root(i));
    }

    cout << T.size() << endl;
    return 0;

}