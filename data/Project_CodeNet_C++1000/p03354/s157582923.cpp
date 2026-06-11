#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
#define dup(x,y) (((x)+(y)-1)/(y))
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
const int INTMAX = 2147483647;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

struct UnionFind {
    vector<int> d;
    UnionFind(int n): d(n,-1) {}
    int root(int x) {
        if (d[x] < 0) return x;
        return d[x] = root(d[x]);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return root(x) == root(y);}
    int size(int x) { return -d[root(x)];}
};

int main(){
    int n,m;cin >> n >> m;
    vi p(n);
    rep(i,n) cin >> p[i];

    UnionFind uf(n);
    rep(i,m){
        int a,b;cin >> a >> b;
        --a;--b;
        uf.unite(a,b);
    }

    int ans = 0;
    rep(i,n){
        if(uf.same(i,p[i]-1)) ++ans;
    }
    cout << ans << endl;
}