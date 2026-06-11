#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

struct UnionFind {
    // par[i]: iの親の番号　(例) par[3] = 99 : 3の親が99
    // cnt[i]: 各枝に含まれる点の個数。
    //         全部更新してるわけじゃないので、cnt[root[i]]を見に行くこと。
    vector<int> par;
    vector<int> cnt;

    UnionFind(int N) : par(N), cnt(N) {    // 初期化
        for (int i = 0; i < N; i++) {
            par[i] = i;
            cnt[i] = 1;
        }
    }

    void print() {
        for (int i = 0; i < par.size(); i++)
            printf("par[%d] = %d\n", i, par[i]);

        for (int i = 0; i < par.size(); i++)
            printf("cnt[%d] = %d\n", i, cnt[i]);
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {    // xとyの木を併合
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (cnt[rx] < cnt[ry]) {
            par[rx] = ry;
            cnt[ry] += cnt[rx];
        } else {
            par[ry] = rx;
            cnt[rx] += cnt[ry];
        }
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size() {
        int N = par.size();
        set<int> s;
        for (int i = 0; i < N; i++) {
            s.insert(root(i));
        }
        return s.size();
    }

    int count(int x) {
        return cnt[root(x)];
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vec<int> p(N);
    rep(i, N) cin >> p[i], --p[i];
    UnionFind uf(N);
    rep(i, M) {
        int x,y;
        cin >> x >> y, --x, --y;
        uf.unite(x,y);
    }

    int ans = 0;
    rep(i,N) {
        if(uf.same(i,p[i])) ++ans;
    }
    cout << ans << endl;
}