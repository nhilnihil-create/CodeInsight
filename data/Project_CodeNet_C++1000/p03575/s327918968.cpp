#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
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

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);
    for(int im=0;im<m;im++) {
        cin >> a.at(im) >> b.at(im); a.at(im)--; b.at(im)--;
    }

    int ans = 0;
    for(int im=0;im<m;im++) {
        UnionFind u(n);
        for(int jm=0;jm<m;jm++) {
            if(im==jm) continue;
            u.merge(a.at(jm), b.at(jm));
        }
        bool flg = false;
        for(int in=0;in<n;in++) {
            for(int jn=in;jn<n;jn++) {
                if(!u.issame(in, jn)) {
                    flg = true;
                }
            }
        }
        if(flg) ans++;
    }
    cout << ans << endl;
    return 0;
}
