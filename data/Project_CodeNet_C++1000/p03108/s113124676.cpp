// #include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

#define all(x) begin(x), end(x)
#define rep(i,n) for(int i=0; i<n; i++)

struct UnionFind {
    vector<int> par, rank, _size;
    
    UnionFind(int n) : par(n), rank(n, 1), _size(n, 1) {
        for (int i=0; i<n; i++) par[i] = i;
    }
    
    int find(int x) {
        if (par[x]==x) return x;
        else return par[x] = find(par[x]);
    }

    bool same(int x, int y) {
        x = find(x); y = find(y);
        return x == y;
    }

    void unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return;

        _size[x] = _size[y] = _size[x] + _size[y];
        if(rank[x] == rank[y]) rank[y]++;

        if(rank[x] > rank[y]) par[y] = x;
        else par[x] = y;
    }

    int size(int x) {
        return _size[find(x)];
    }
};


int main() {
    int n;
    int m;
    cin >> n >> m;

    int a[m], b[m];
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }

    ll ans[m];
    UnionFind island(n);
    ans[m-1] = (ll)n*(n-1)/2;

    for (int i=m-1; i>=0; i--) {
        ll size_a = island.size(a[i]);
        ll size_b = island.size(b[i]);
        if (island.same(a[i], b[i])) ans[i-1] = ans[i];
        else ans[i-1] = ans[i] - size_a*size_b;
        island.unite(a[i], b[i]);
    }

    rep(i, m) cout << ans[i] << endl;

    return 0;
}