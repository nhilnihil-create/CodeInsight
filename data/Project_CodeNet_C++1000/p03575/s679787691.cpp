#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    void rereset(int n){ 
        for(int i=0;i<n;i++)par[i] = i;
    }
    void reset(int n){ 
        for(int i=0;i<n;i++)par[i] = root(par[i]);
    }
    bool solve(int n) {
        int num=0; 
        for(int i=0;i<n;i++)if(par[i]==par[0])num++;
        return num==n;
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    int a,b;
    pair<int,int> p[m];
    for(int i=0;i<m;i++){
        cin >> a >> b;
        a--; b--;
        p[i]=make_pair(a,b);
    }
    UnionFind tree(n);   
    int ans=0;
    for(int i=0;i<m;i++){
        tree.rereset(n);
        for(int j=0;j<m;j++)if(j!=i)tree.unite(p[j].first,p[j].second);
        tree.reset(n);
        ans += (1-tree.solve(n));
    }
    cout << ans;
    return 0;
}