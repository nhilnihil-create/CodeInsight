#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0): d(n, -1) {}
    int find(int x) {
        if (d[x]<0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x==y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return -d[find(x)];
    }
};

int main(){
    ll n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    UnionFind u(n);
    vector<ll> ans(m);
    ans[m-1] = n*(n-1)/2;

    for (ll i=m-1; i>=0; i--) {
        if (i==0) continue;
        if (u.same(a[i], b[i])) {
            ans[i-1] = ans[i];
            continue;
        }
        ll res = u.size(a[i])*u.size(b[i]);
        u.unite(a[i], b[i]); 
        ans[i-1] = ans[i] - res;
    }

    rep(i, m) {
        cout << ans[i] << endl;
    }
    
    
    return 0;
}
