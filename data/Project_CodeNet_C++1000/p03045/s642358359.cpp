#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define rep(i,n) for(int64_t i=0;i<n;++i)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr int64_t INF=(1ll<<60);
constexpr int64_t mod=1000000007;
constexpr double pi=3.14159265358979323846;
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


int main(){
    ll n,m;cin>>n>>m;
    
    UnionFind uf(n);
    vector<bool> ans(n);

    rep(i,m){
        ll x,y,z;
        cin>>x>>y>>z;
        x--;y--;z%=2;

        uf.unite(x,y);
    }

    rep(i,n){
        ans[uf.root(i)]=true;
    }

    ll sum=0;
    rep(i,n){
        if(ans[i]==true) sum++;
    }

    cout<<sum<<endl;
    return 0;
}