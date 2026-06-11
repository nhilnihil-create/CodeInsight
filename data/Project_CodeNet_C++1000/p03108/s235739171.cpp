#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(obj) rbegin(obj),rend(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 30);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    fill((T*)array, (T*)(array + N), val);
}
struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
    ll n, m; cin >> n >> m; vector<int> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }vector<ll> ans; ll res = n * (n - 1) / 2;
    UnionFind tree(n);
    rrep(i, m) {
        ans.push_back(res);
        int c = a[i], d = b[i];
        if (tree.same(c, d)) continue;
        ll sa = tree.size(c), sb = tree.size(d);
        res -= sa * sb;
        tree.unite(c, d);
    }reverse(ALL(ans));
    for (ll i : ans) cout << i << endl;
}