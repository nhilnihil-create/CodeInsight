#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

struct UnionFind{
    vector<ll> par;
    vector<ll> sizes;
    UnionFind(ll n) : par(n), sizes(n, 1) {
        rep(i,n) par[i] = i;
    }
    int find(ll x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void unite(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }

    bool same(ll x, ll y) {
        return find(x) == find(y);
    }

    ll size(ll x) {
        return sizes[find(x)];
    }
};

ll x[100010];
ll y[100010];
ll z[100010];

bool seen[100010];

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m) cin >> x[i] >> y[i] >> z[i];
    rep(i, m) x[i]--, y[i]--;

    UnionFind tree(n);
    int cnt = n;
    rep(i, m){
        if (!tree.same(x[i], y[i])) cnt--;
        tree.unite(x[i], y[i]);
    }

    cout << cnt << endl;

    return 0;
}