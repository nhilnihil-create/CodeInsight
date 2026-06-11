#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

// UnionFindの実装
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }

    // 集合をマージする
    // すでに同じ集合ならfalseが返る
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if(x == y) return false;
        //要素数の少ない方を多い方に繋げる
        if(data.at(y) < data.at(x)) swap(x, y);
        data.at(x) += data.at(y);
        data.at(y) = x;
        return true;
    }

    // ある要素がどの集合に属しているかを返す
    int root(int x) {
        // 根に直接つなぎ直す
        return data.at(x) < 0 ? x : (data.at(x) = root(data.at(x)));
    }

    // ある集合の大きさを答える
    int size(int x) {
        return -data.at(root(x));
    }

    // ある二つの要素が同じ集合か判定
    bool same(int x, int y) {
        x = root(x); y = root(y);
        return x == y;
    }
};


int n, m;
vector<int> x(100100, 0);
vector<int> y(100100, 0);
vector<int> z(100100, 0);
vector<int> A(100100, 0);

int main() {
    cin >> n >> m;
    UnionFind tree(n);
    for(int i = 0; i < m; ++i) {
        cin >> x.at(i) >> y.at(i) >> z.at(i);
        x.at(i)--; y.at(i)--;
        tree.merge(x.at(i), y.at(i));
    }

    int ans = 0;
    set<int> rcnt;
    for(int i = 0; i < n; ++i) {
        rcnt.insert(tree.root(i));
    }

    ans += rcnt.size();
    cout << ans << endl;
}