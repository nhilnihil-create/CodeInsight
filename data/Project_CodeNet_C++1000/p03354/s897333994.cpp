#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P; 
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// DAME:

class UnionFind {
    // 経路圧縮によるrank更新はなし
    public:
        vector<int> rank, par, size; // rank[x]: xの高さ, par[x]: xの親のノード, size[x]: x

    // 初期化
    UnionFind() {}
    UnionFind(int size){
        rank.resize(size, 0);
        par.resize(size, 0);
        rep(i, size) makeSet(i);
    }

    void makeSet(int x){
        par[x] = x;
        rank[x] = 1;
    }

    // 根を再帰的に求める(経路圧縮)
    int findRoot(int x){
        if(x != par[x]){
            par[x] = findRoot(par[x]);
        }
        return par[x];
    }

    // 根が同じかどうか
    bool same(int x, int y){
        return findRoot(x) == findRoot(y);
    }

    //  xとyの木を併合
    bool unite(int x, int y){
        x = findRoot(x);
        y = findRoot(y);
        if(x==y) return false;
        if(rank[x]<rank[y]) swap(x, y);

        // 単純に繋げない場合, makeSetのrank[x] = 0にするのを忘れずに
        // if(rank[x]==rank[y]) rank[x]++;


        // 単純に一列につなげる場合
        rank[x] += rank[y];


        par[y] = x;
        return true;
    }

    int getRank(int x){
        return rank[findRoot(x)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n){
        int tmp;
        cin >> tmp;
        tmp--;
        p[i] = tmp;
    }
    UnionFind ds = UnionFind(n);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        ds.unite(x, y);
    }
    int ans = 0;
    rep(i, n){
        if (ds.same(i, p[i])) ans++;
    }

    cout << ans << endl;
    return 0;
}