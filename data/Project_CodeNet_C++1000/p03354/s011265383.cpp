#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

struct UnionFind {
    // par[i]:iの親の番号　(例) par[3] = 99 : 3の親が99
    vector<int> par;

    UnionFind(int N) : par(N) {  // 初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    void print(){
       for (int i = 0; i < par.size(); i++)
            printf("par[%d] = %d\n",i, par[i]);
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {  // xとyの木を併合
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(){
        int N = par.size();
        set<int> s;
        for (int i = 0; i < N; i++) {
            s.insert(root(i));
        }
        return s.size();
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);
    
    vec<int> p(N);
    rep(i, N) {
        cin >> p[i];
        --p[i];
    }
    
    vec<int> x(M), y(M);
    rep(i, M) {
        cin >> x[i] >> y[i];
        --x[i],--y[i];
        uf.unite(x[i],y[i]);
    }

    int ans = 0;
    rep(i,N){
        uf.same(i,p[i]) && ++ans;
    }
    cout << ans << '\n';
}
