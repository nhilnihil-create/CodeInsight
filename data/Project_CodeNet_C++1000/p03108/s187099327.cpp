#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, K, tmp=0;
vector<ll> ans;
vector<pair<ll,ll>> G;

struct UnionFind {
    vector<int> size, parents;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        size.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        size[x] = 1;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (size[x] > size[y]) {
            parents[y] = x;
            size[x] += size[y];
        } else {
            parents[x] = y;
            size[y] += size[x];
        }
        return true;
    }
    int findRoot(int x) {
        if (x != parents[x]) {
            parents[x] = findRoot(parents[x]);
        }
        return parents[x];
    }
    int treeSize(int x) { return size[findRoot(x)]; }
};

signed main(){
    cin >> N >> K;
    UnionFind tree(N);
    for(int i=0;i<K;i++) {
        ll a, b;
        cin >> a >> b;
        G.push_back(make_pair(a,b));
    }
    ans.push_back(N*(N-1)/2);
    while(!G.empty()) {
        pair<ll,ll> p = G.back();
        G.pop_back();
        if(!tree.isSame(p.first-1, p.second-1)) ans.push_back(ans.back()-tree.treeSize(p.first-1)*tree.treeSize(p.second-1));
        else ans.push_back(ans.back());
        tree.unite(p.first-1, p.second-1);
    }
    ans.pop_back();
    for(int i=0;i<K;i++) {        
        cout << ans.back() << endl;
        ans.pop_back();
    }
    return 0;
}