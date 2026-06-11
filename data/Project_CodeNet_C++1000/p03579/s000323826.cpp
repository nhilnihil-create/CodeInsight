#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


//UnionFind
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int n) : par(n, -1) { }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool merge(int x, int y) {//xの木とyの木を結合する
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {//sizeの取得
        return -par[root(x)];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};



int main(){
    ll n,m;
    cin >> n >> m;
    UnionFind u(n*2);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        u.merge(a,b+n);
        u.merge(b,a+n);
    }
    if(u.same(0,n)){
        cout << n*(n-1)/2-m << endl;
        return 0;
    }
    else{
        ll ans = 0;
        rep(i,n){
            if(u.same(0,i)){
                ans++;
            }
        }
        cout << ans * (n-ans)-m << endl;
        return 0;
    }
}
