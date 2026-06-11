#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){
    ll n = vec.size();
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
}

void pr2d(vector<vector<ll>> vvec){
    ll h = vvec.size();
    ll w = vvec.at(0).size();
    rep(i,h){
        rep(j,w){
            cout << vvec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    //UnionFindのデータはparで構成されていて、[name].parでアクセスできる
    vector<int> rank; 
    vector<int> unsize;

    UnionFind(ll N) : par(N), rank(N), unsize(N){ //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i, rank[i] = 0, unsize[i] = 1;
    }

    int root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    ll unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        ll ret = 0;
        if(rx!=ry){
            ret = unsize[rx]*unsize[ry];
        }
        if(rank[rx] < rank[ry]){ //木の長さが低い方を高い方に繋げる
            par[rx] = ry;
            unsize[ry] += unsize[rx];
        }else if(rank[rx] > rank[ry]){
            par[ry] = rx;
            unsize[rx] += unsize[ry];
        }else if(rx != ry){
            par[ry] = rx;
            if(rank[rx] == rank[ry]) rank[rx]++;
            unsize[rx] += unsize[ry];
        }
        return ret;
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main(){
    ll n , m ; cin >> n >> m;
    vector<ll> a(m),b(m);
    rep(i,m){
        ll ai,bi;
        cin >> ai >> bi ;
        ai--; bi--;
        a.at(i) = ai;
        b.at(i) = bi;
    }

    UnionFind tree(n);
    vector<ll> noct(m+1,0); //The number of Connected Towns
    ll dif;

    for(int i=m-1;i>=0;i--){
        ll aa=a.at(i), bb = b.at(i);
        dif = tree.unite(aa,bb);
        if(i==m-1){
            noct.at(i) = dif;
        }else{
            noct.at(i) = noct.at(i+1) + dif;
        }
    }

    //prvec(noct);

    ll all = n*(n-1)/2;

    for(int i=1;i<=m;i++){
        noct.at(i) = all - noct.at(i);
        cout << noct.at(i) << "\n";
    }
    return 0;
}

