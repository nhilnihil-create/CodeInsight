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

    ll n,m;
    cin >> n >> m;
    vector<ll> a(m),b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    
    UnionFind uf(n);
    vector<ll> ans;
    
    ll cur = n *(n-1)/2;
    for(int i=m-1; i>=0; i--) {
        ans.push_back(cur);
        if(uf.same(a[i], b[i])) continue;
        ll sa = uf.size(a[i]);
        ll sb = uf.size(b[i]);
        cur -= sa * sb;
        uf.unite(a[i], b[i]);
    }
    
    for(int i=m-1; i>=0; i--) cout << ans[i] << endl;
    return 0;
}