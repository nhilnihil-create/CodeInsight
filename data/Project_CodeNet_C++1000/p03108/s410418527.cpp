#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

struct UnionFind {
    vector<int> par;
    UnionFind(int n) :par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool connect(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll a[m], b[m];
    for(int i=0;i<m;i++){
    	cin >> a[i] >> b[i];
    	a[i]--;b[i]--;
    }
    UnionFind uf(n);
    vector<ll> v;
    ll ans = n * (n - 1) / 2;
    v.pb(ans);

    for(int i=m-1;i>=1;i--){
        ll c = uf.size(a[i]);
        ll d = uf.size(b[i]);
        if(uf.root(a[i]) != uf.root(b[i])) ans -= c * d;
        uf.connect(a[i], b[i]);
        v.pb(ans);
    }
    reverse(be(v));
    for(int i=0;i<m;i++){
    	cout << v[i] << endl;
    }

    return 0;
}
