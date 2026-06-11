#include <bits/stdc++.h>
using namespace std;
#ifdef ENABLE_DEBUG_OUTPUT
#define DEBUG_LOG(s) cout << s << endl;
#else
#define DEBUG_LOG(s) void();
#endif

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
        for (auto i = 0; i < (int)parent.size(); i++) {
            cout << parent[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    UnionFindTree tree(n);

    vector<int> p(n);
    for (auto i = 0; i < n; i++) cin >> p[i];

    for (auto i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        tree.unite(--x, --y);
    }

    uint64_t ans = 0;
    for (auto i = 0; i < n; i++) {
        if(tree.is_same_root(--p[i], i)) ans++;
    }

    cout << ans << endl;
    return 0;
}