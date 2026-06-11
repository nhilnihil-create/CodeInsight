#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

struct UnionFind{
    //iの親番号
    vector<int> par;

    //コンストラクタ
    UnionFind(int N) : par(N){
        for(int i = 0;i < N; i++) par[i] = i;
    }

    //根を見つける
    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    //2つの木を併合
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        par[rx] = ry;
    }

    //所属が同じか
    bool same(int x,int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


int main(){
    fast_io

    int n, m;
    cin>>n>>m;
    vector<int> P(n);
    rep(i,n) cin>>P[i];

    UnionFind tree(n);

    rep(i,m){
        int x, y;
        cin>>x>>y;
        tree.unite(x-1, y-1);
    }
    int cnt=0;
    rep(i,n){
        if(tree.same(i, P[i]-1)){
            cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}