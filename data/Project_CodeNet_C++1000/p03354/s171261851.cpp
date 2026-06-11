#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

struct UnionFind{
    vector<int> p; // p[i]: 頂点iの親の番号

    // 初期化 -> 自分の親は自分自身
    UnionFind(int n){
        rep(i,n) p.push_back(i);
    }

    // 頂点xに対応する木の根を見つける
    int root(int x){
        if (p[x] == x) return x;
        else return p[x] = root(p[x]);
    }

    // 頂点xの木と頂点yの木を統合
    void unite(int x, int y){
        x = root(x); y = root(y);
        if (x != y) p[x] = y;
    }

    bool same(int x, int y){
        return (root(x) == root(y));
    }
};

int main(){
    int N, M; cin >> N >> M;
    vector<int> position(N);
    rep(i, N){
        int P; cin >> P; P--;
        position[P] = i;
    }

    UnionFind UF(N);
    rep(i, M) {
        int x, y; cin >> x >> y; x--; y--;
        UF.unite(x,y);
    }

    int ans = 0;
    rep(i,N){
        if(UF.root(position[i]) == UF.root(i)) ans++;
    }
    cout << ans << endl;
}