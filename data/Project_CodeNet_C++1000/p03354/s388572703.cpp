#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

class UnionFindTree {
  private:
    std::vector<int> par;   // 親
    std::vector<int> depth; // 木の深さ

  public:
    // n要素で初期化
    UnionFindTree(int n) {
        for (int i = 0; i < n; i++) {
            par.push_back(i);
            depth.push_back(0);
        }
    }

    // 木の根を求める
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    // xとyの属する集合を併合
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (depth[x] < depth[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (depth[x] == depth[y])
                depth[x]++;
        }
    }

    // xとyが同じ集合に属するか否か
    bool same(int x, int y) { return find(x) == find(y); }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for(int i=0;i<n;++i){
        int p;
        cin >> p;
        v.push_back(p);
    }
    UnionFindTree uft(n+1);
    for(int i=0;i<m;++i){
        int x, y;
        cin >> x >> y;
        uft.unite(x, y);
    }
    int ans = 0;
    for(int i=0;i<n;++i){
        if(uft.same(i+1, v[i]))ans++;
    }

    cout << ans << endl;

    return 0;
}