#include <bits/stdc++.h>
#define ll long long
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll i,j,k,l,m,n,w,z=0,p,q,tmp,sum=0;
    string str;
    cin>>n>>m;
    vector<ll> cnt(n+1);
    vector<ll> x(m+1);
    vector<ll> y(m+1);
    rep(i,m){
        cin>>x[i]>>y[i];
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    for(ll i=1;i<n;i++){
        z+=i;
    }
    l=z;
    UnionFind t(n+1);
    t.init(n);
    vector<ll> d(m+1000000);
    d[m-1]=z;
    for(i=0;i<m;i++){
        //cout<<z<<endl;
        ll lastx,lasty,nowx,nowy;
        lastx=t.size(x[i]);
        lasty=t.size(y[i]);

        t.merge(x[i],y[i]);
        nowx=t.size(x[i]);
        nowy=t.size(y[i]);
        z=z-(nowx-lastx)*(nowy-lasty);
        d[m-i-1]=z;
    }
    rep(i,m) cout<<d[i]<<endl;

    //cout<<l<<endl;
    //cout<<sum<<endl;

    return 0;
}



