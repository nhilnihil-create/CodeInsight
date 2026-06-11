#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define ALL(v) (v).begin(),(v).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
struct UnionFind {
    vector<int> par,siz; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) , siz(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
        for(int i = 0; i < N; i++) siz[i] = 1;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        siz[rx]+=siz[ry];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    int size(int x){
        return siz[root(x)];
    }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin >> n >> m;
    UnionFind uf(n);
    REP(i,m){
        int x,y,z;cin >> x >> y >> z;
        x--,y--;
        uf.unite(x,y);
    }
    int ans=0;
    REP(i,n){
        if(uf.root(i)==i){
            ans++;
        }
    }
    cout << ans << endl;
}