#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using Tu = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;

class UnionFind {
public:
    vector < ll > par; // 各元の親を表す配列
    vector < ll > siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
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
    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};


int main(){
    ll N;
    cin >> N;
    ll M;
    cin >> M;
    vector<ll> A(M,0);
    vector<ll> B(M,0);
    for(ll i=0;i<M;i++){
        cin>>A[i]>>B[i];
        A[i]--;B[i]--;
    ;}
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    UnionFind tree(N);
    vector<ll> ans(M,0);
    ll Ans=N*(N-1)/2;
    multiset<ll> S;
    for(ll i=0;i<N;i++){
        S.insert(1)
    ;}  
    for(ll i=0;i<M;i++){
        ans[M-1-i]=Ans;
        if(!tree.same(A[i],B[i])){
            ll x=tree.size(A[i]);
            ll y=tree.size(B[i]);
            Ans-=x*y;
            tree.unite(A[i],B[i]);
            S.erase(*S.lower_bound(x));
            S.erase(*S.lower_bound(y));
            S.insert(x+y);
        }
        
    ;}
    for(ll i=0;i<M;i++){
        cout<<ans[i]<<endl;
    ;}



    return 0;
}
