#include <bits/stdc++.h>
using namespace std;

class UnionFindTree {
private:
    vector<int> parent;
public:
    UnionFindTree(int n) : parent(n) {
        // 最初は全てを根として初期化
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int get_root(const int x) {
        // データxが属する木の根を取得する
        if (parent[x] == x) return x;
        // 取得したものは直接木の根をつなぐ(経路圧縮)
        return parent[x] = get_root(parent[x]);
    }

    void unite(const int x, const int y) {
        // xとyの木を併合する
        int rx = get_root(x);
        int ry = get_root(y);
        // 元から同じ木に属している場合は何もしない
        if (rx == ry) return;
        // xの属する木をyの属する木につける
        parent[rx] = ry;
    }

    bool is_same_root(const int x, const int y) {
        return get_root(x) == get_root(y);
    }

    void print() {
        for(auto elm : parent) cout << elm << " ";
        cout << endl;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> p;
    for (auto i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        p.emplace_back(a, b);
    }

    int ans = 0;
    for (auto i = 0; i < m; i++) {
        UnionFindTree tree(n);
        for (auto j = 0; j < m; j++) {
            if(i == j) continue;
            tree.unite(p[j].first, p[j].second);
        }
        int cnt = 0;
        for (auto j = 0; j < n; j++) {
            if(tree.get_root(j) == j) {
                cnt++;
            }
        }
        if(cnt != 1) ans++;
//        cout << i << endl;
//        tree.print();
    }

    cout << ans << endl;
    return 0;
}