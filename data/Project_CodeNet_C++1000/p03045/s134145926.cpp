#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct UnionFind{
    vector<int> par, size;
    UnionFind(int x) {
        par.resize(x);
        size.resize(x, 1);
        for(int i = 0; i < x; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int consize(int x) {
        return size[find(x)];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (size[x] < size[y]) {
            par[x] = y;
            size[y] += size[x];
        }
         else {
            par[y] = x;
            size[x] += size[y];
        }
    }
};
signed main(){
    int N,M;
    cin >> N >> M;
    UnionFind uf(N);
    for(int i = 0; i < M; i++) {
        int X,Y,Z;
        cin >> X >> Y >> Z;
        X--;Y--;
        uf.unite(X,Y);
    }
    set<int>st;
    for(int i = 0; i < N; i++) {
        int X = uf.find(i);
        st.insert(X);
    }
    cout << st.size() << endl;
}