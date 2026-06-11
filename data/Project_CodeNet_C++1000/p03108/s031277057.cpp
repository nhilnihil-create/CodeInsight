#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;


struct UnionFind {
    vector<int> size;
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N), size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        par[x] = root(par[x]);
        return par[x];
    }

    int getSize(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        return size[root(x)];
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y); 
        if (rx == ry) return;
        if (size[rx] < size[ry]) swap(x, y);
        size[rx] += size[ry];
        par[ry] = rx; 
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

void Main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> A(m), B(m);
    rep(i, m) cin >> A[i] >> B[i];
    
    UnionFind uf(n);

    vector<ll> inc(m);
    
    for (ll i = m - 1; i >= 0; i--) {
        ll a = A[i] - 1;
        ll b = B[i] - 1;
        if (uf.root(a) != uf.root(b)) {
            inc[i] = uf.getSize(a) * uf.getSize(b);
        }
        uf.unite(a, b);
    }

    ll res = 0;
    rep(i, m) {
        res += inc[i];
        put(res);
    }

}
signed main(){ Main();return 0;}