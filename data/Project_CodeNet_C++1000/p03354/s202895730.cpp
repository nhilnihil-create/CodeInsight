#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define inf 1001001001001000
#define mod 1000000007
using namespace std;

struct UnionFind {
    vl par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(ll n) : par(n) { //最初は全てが根であるとして初期化
        rep(i,n) par[i] = i;
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main(void){
    ll n,m;
    cin>>n>>m;
    vl p(n),ip(n);
    rep(i,n){
        cin>>p[i];
        p[i]--;
        ip[p[i]] = i;
    }
    UnionFind uf(n);
    rep(i,m){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        uf.unite(x,y);
    }
    ll ans = 0;
    rep(i,n){
        if(uf.same(i,ip[i])) ans++;
    }
    cout<<ans<<endl;
}
