#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

class UnionFind {
public:
    vector<LL> parent;
    vector<LL> member;

    UnionFind(LL N) {
        parent.resize(N);
        REP(i, N) {
            parent[i] = i;
        }
        member.resize(N);
        fill(ALL(member), 1);
    }

    int root(LL x) {
        if(x == parent[x]) {
            return x;
        }
        return parent[x] = root(parent[x]);
    }

    bool same(LL x, LL y) {
        return root(x) == root(y);
    }

    LL size(LL x) {
        return member[root(x)];
    }

    void unite(LL x, LL y) {
        if(root(x) == root(y)) {
            return;
        }
        member[root(y)] += member[root(x)];
        parent[root(x)] = root(y);
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N + 1);
    FOR(i, 1, N + 1) {
        cin >> p[i];
    }
    UnionFind uf(N + 1);
    REP(i, M) {
        int x, y;
        cin >> x >> y;
        uf.unite(x, y);
    }
    vector<set<int>> vs(N + 1);
    vector<vector<int>> vo(N + 1);
    FOR(i, 1, N + 1) {
        int x = uf.root(i);
        vs[x].insert(p[i]);
        vo[x].push_back(i);
    }
    int res = 0;
    FOR(i, 1, N + 1) {
        for(auto j : vo[i]) {
            if(vs[i].find(j) != vs[i].end()) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
