#include "bits/stdc++.h"
using namespace std;
const int MOD = 1e9 + 7;
typedef long long lint;
const int INF = 1e7;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repi(i, k, n) for (int i = (k); i < (int)(n); ++i)
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;
    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }
    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }
    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }
    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    UnionFind<int> uf(n);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if(uf.same(a,b)){
            int diff = uf.diff(a, b);
            if(diff!=c){
                cout << "No" << endl;
                return 0;
            }
        }
        else
        {
            uf.unite(a, b, c);
        }
    }
    cout << "Yes" << endl;
    return 0;
}