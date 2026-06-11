#include<bits/stdc++.h>

using namespace std;

struct WeightedUnionFind {
    std::vector<int> par; // pos: parent node, neg: rank of tree
    std::vector<int> dw;

    WeightedUnionFind(int N) : par(N, -1), dw(N, 0) {}

    int find(int x){
        if(par[x] < 0) return x;
        int p = find(par[x]);
        dw[x] = dw[par[x]] + dw[x];
        return par[x] = p;
    }

    int weight(int x){
        find(x);
        return dw[x];
    }

    bool unite(int x, int y, int w){ // x+w = y
        w = w + weight(x) - weight(y);
        x = find(x); y = find(y);
        if(x == y) return false; // unspecified.

        int rx = -par[x], ry = -par[y];
        if(rx < ry){ // merge technique
            std::swap(x, y);
            w = -w;
        }
        par[x] = -(rx+ry);
        par[y] = x;
        dw[y] = w;
        return true;
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int dist(int x, int y){ // x, y must be in same group.
        return weight(y) - weight(x);
    }
};


int main(void){
    int N, M;
    cin >> N >> M;
    WeightedUnionFind wuf(N);
    for(int i=0;i<M;i++){
        int L, R, D;
        cin >> L >> R >> D;

        if(wuf.same(L, R) && wuf.dist(L, R) == D) continue;

        if(wuf.unite(L, R, D) == false){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}