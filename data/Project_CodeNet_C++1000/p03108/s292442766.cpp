#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

// UnionFind
struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n, -1) {} // each node has "minus-size"
    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (-d[x] < -d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -d[find(x)];}
    int component() {
        set<int> S;
        rep(x,d.size()) S.insert(find(x));
        return S.size();
    }
};

ll comb2(ll n) {return n*(n-1)/2;}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        v.push_back(make_pair(a,b));
    }
    ll S[m+1];
    rep(i,m+1) S[i] = 0;
    S[m] = comb2(n);

    UnionFind un(n);
    for (int i=m-1; i>=0; i--) {
        int a = v[i].first;
        int b = v[i].second;
        if (un.same(a,b)) {
            S[i] = S[i+1];
            continue;
        }

        int x = un.size(a);
        int y = un.size(b);
        un.unite(a,b);
        int z = un.size(a);
        S[i] = S[i+1] + comb2(x) + comb2(y) - comb2(z);   
    }

    for (int i= 1; i<=m; i++) {
        cout << S[i] << endl;
    }
    
    return 0;
}
