#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
//issame:同じか判定
//unite:併合
//findroot:根の検索
//treesize:その木の要素数
struct UnionFind{
    vector<long long> size, par;
    UnionFind(long long n) {
        size.resize(n, 0);
        par.resize(n, 0);
        for (long long i = 0; i < n;i++){
            maketree(i);
        }
    }
    void maketree(long long x){
        par[x] = x;
        size[x] = 1;
    }
    long long findroot(long long x){
        if (x != par[x]) par[x] = findroot(par[x]);
        return par[x];
    }
    bool issame(long long x,long long y){
        return findroot(x) == findroot(y);
    }
    bool unite(long long x,long long y){
        x = findroot(x);
        y = findroot(y);
        if (x == y) return false;  //already united
        if(size[x]>size[y]){
            par[y] = x;
            size[x] += size[y];
        }
        else{
            par[x] = y;
            size[y] += size[x];
        }
        return true;
    }
    long long treesize(long long x){
        return size[findroot(x)];
    }
};

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    vector<ll> ans(m, 0);
    UnionFind uf(n);
    ans[m - 1] = n * (n - 1) / 2;
    for (ll i = m - 2; i >= 0; i--) {
        if (uf.issame(a[i+1],b[i+1]))
            ans[i] = ans[i + 1];
        else {
            ans[i] = ans[i + 1] - uf.treesize(a[i+1]) * uf.treesize(b[i+1]);
        }
		uf.unite(a[i+1], b[i+1]);
    }
    for (ll i = 0; i < m;i++){
        cout << ans[i] << endl;
    }
}