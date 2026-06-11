#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#include<iomanip>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define rrep(i,n) for(int i = n-1;i >=0;i--)
#define ALL(a) a.begin(),a.end()
#define PI  acos(-1)
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
typedef long double ld;
const int MOD = 1e9 + 7;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 }, sum = 0,h,w;
struct UnionFind {
    vector<int> par, sz;
    UnionFind(int n) :par(n), sz(n) {
        rep(i, n) par[i] = i, sz[i] = 0;
    }
    int root(int x) {
        if (par[x] == x) return x;
        return root(par[x]);
    }
    bool unite(int x, int y) {
        if (root(x) == root(y)) return 0;
        par[root(x)] = root(y);
        return 1;

    }bool same(int x, int y) {
        return root(x) == root(y);
    }
};
int main() {
    int n, m,a,b; cin >> n >> m; vector<pair<int,int>> G;
    rep(i, m) {
        cin >> a >> b; a--; b--;
        G.push_back({ a,b });
    }int ans = 0;
    rep(i, m) {
        UnionFind uf(n);
        rep(j, m) {
            if (j == i) continue;
            uf.unite(G[j].first, G[j].second);
        }bool f = 0;
        rep(j, n) {
            for (int k = j + 1; k < n; k++) {
                if (uf.same(j, k)) continue;
                ans++; f = 1; break;
            }if (f) break;
        }
    }cout << ans << endl;
}