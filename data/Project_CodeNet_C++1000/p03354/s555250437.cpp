#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e8
#define INF_LL 1LL<<60
#define ll long long
#define MAX_V 100005

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> rank;
    vector<int> size; // size[i]: iが親なら連結成分の数
 
    UnionFind(int N) : par(N), rank(N), size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {par[i] = i; rank[i] = 0; size[i] = 1;}
    }
 
    int find(int x) { // データxが属する木の根を再帰で得る：find(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }
 
    void unite(int x, int y) { // xとyの木を併合
        int rx = find(x); //xの根をrx
        int ry = find(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
 
        // rank[rx] >= rank[ry] となるように rx と ry を swap
        if(rank[rx] < rank[ry]) swap(rx, ry);
 
        // 同じ高さだったならばまとめたことによって高さ +1
        if(rank[rx] == rank[ry]) ++rank[rx];
 
        par[ry] = rx; // root rx に ry の木をつなぐ
        size[rx] += size[ry];
        size[ry] = 0;
 
    }
 
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
 
    int get_size(int x){
        int rx = find(x);
        return size[rx];
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    UnionFind uf(n);

    REP(i, m) {
        int x, y;
        cin >> x >> y;
        uf.unite(x-1, y-1);
    } 

    int ans = 0;

    REP(i, n) {
        if(uf.same(i, a[i]-1)) ans++;
    }
 
    cout << ans << endl;
 
}
 