#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct UnionFind{
    vector<ll> d;
    UnionFind(ll n): d(n,-1) {}
    ll find(ll x){
        if(d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(ll x, ll y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(d[x] < d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(ll x,ll y){
        return find(x)==find(y);
    }
    ll size(ll x){
        return -d[find(x)];
    }
};

//#define ll long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> b(m);
    for(ll i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    vector<ll> ans(m+1);
    ans[m]=n*(n-1)/2;
    UnionFind uf(n);
    for(ll i = 0; i < m; i++) {
        ll ta=a[m-1-i]-1;
        ll tb=b[m-1-i]-1;
        ll dec=abs(uf.size(ta)*uf.size(tb));
        if(uf.same(ta,tb)) dec=0;
        ans[m-i-1]=ans[m-i]-dec;
        uf.unite(ta,tb);
    }
    for(ll i = 0; i < m; i++) {
        cout << ans[i+1] << "\n";
    }

    return 0;
}
