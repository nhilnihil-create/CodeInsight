#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string,ll>;
using Map = map<char,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(ll N) : par(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) par[i] = i;
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { // xとyの木を併合
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

int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> P(N+1,0);
    vector<ll> X(M,0);
    vector<ll> Y(M,0);
    for(ll i=1;i<=N;i++){
        cin>>P[i]
    ;}
    for(ll i=0;i<M;i++){
        cin>>X[i]>>Y[i]
    ;}

    UnionFind tree(N+1);
    for(ll i=0;i<M;i++){
        tree.unite(X[i],Y[i])
    ;}
    ll ans=0;
    for(ll i=1;i<=N;i++){
        if(tree.same(i,P[i]))ans++;
    ;}
    cout<<ans<<endl;

return 0;
}
