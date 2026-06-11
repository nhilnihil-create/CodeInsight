#include <stdio.h>
#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
#include <queue>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i,k,n) for(ll i=k; i<(ll)(n); i++)
#define Q 1000000007


struct UnionFind {
    vector<ll> par; //par[a]=b: aの親がb

    UnionFind(ll N) : par(N) { //初めは全て根として初期化
        rep(i,0,N) par[i] = i;
    }

    ll root(ll x) { //xの属する根を求める
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { //xとyの木を併合
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return; //根が同じときはそのまま
        par[rx] = ry;
    }

    bool same(ll x, ll y) { //x,y の属する木が同じならtrue
        return root(x) == root(y);
    }
};


int main(){
    ll n,m; cin >> n >> m;
    UnionFind tree(n);
    vector<ll> p(n);
    rep(i,0,n) {
        cin >> p[i];
        --p[i];
    }
    vector<ll> x(m),y(m);
    rep(i,0,m) {
        cin >> x[i] >> y[i];
        --x[i]; --y[i];
        tree.unite(x[i],y[i]);
    }

    ll ans = 0;
    rep(i,0,n) {
        if(tree.same(i,p[i])) {
            // cout << i << "," << p[i] << endl;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}