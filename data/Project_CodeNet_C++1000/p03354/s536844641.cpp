#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> par;
    UnionFind(int n) {
        par.resize(n);
        for(int i=0;i<n;i++) {
            par[i] = i;
        }
    }

    int root(int x) {
        return par[x] == x ? x:par[x] = root(par[x]);
    }

    // 今回不要
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x==y) return ; 
            par[x] = y;
    }
};

int main(void) {
    int N,M,p,x,y;
    int cnt = 0;
    cin >> N >> M;

    UnionFind uf(N);   
    vector<int> tr(N);
    for(int i=0;i<N;i++) {
        cin >> p;
        p--;
        tr[i] = p;
    }

    for(int i=0;i<M;i++) {
        cin >> x >> y;
        x--;y--;
        // xとyを同じグループに属させる 
        uf.unite(x,y);
    }

    // グループ(木)毎にチェック。ってどうやるの？
    // root見れば良いだけ
    for(int i=0;i<N;i++) {
        if(uf.same(i, tr[i])) {
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
