#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

// 逆からやろう
// n[^1] = 階和(n-1)

struct UnionFind {
    vector<int> v;
    vector<int> size;
    int a; // 木の数
    UnionFind(int n) {
        v.resize(n);
        size.resize(n);
        rep(i,n) {
            v[i] = i;
            size[i] = 1;
        }
        a = n;
    }

    int root(int x) {
        if (x == v[x]) return x;
        return v[x] = root(v[x]);
    }

    bool unite(int x, int y) {
        if (root(x) == root(y)) return false;
        size[root(y)] += size[root(x)]; 
        v[root(x)] = v[root(y)];
        return true;
    }

    int cnt(int x) {
        return size[root(x)];
    }

};

int main() {
    int n,m; cin >> n >> m;
    pair<int,int> ab[100000];
    rep(i,m) {
        cin >> ab[i].first >> ab[i].second;
        ab[i].first --;
        ab[i].second --;
    }
    UnionFind uf(n);

    lint ans = 0;
    rep(i,n) ans += i;
    lint anslist[100000] = {0};
    anslist[m-1] = ans;
    for (int i=m-1; i > 0; i--) {
        int x,y;
        x = ab[i].first;
        y = ab[i].second;
        lint cntx = uf.cnt(x);
        lint cnty = uf.cnt(y);
        if(uf.unite(x,y)) ans -= cntx*cnty ;
        anslist[i-1] = ans;
    }
    rep(i,m) {
        cout << anslist[i] << endl;
    }
}