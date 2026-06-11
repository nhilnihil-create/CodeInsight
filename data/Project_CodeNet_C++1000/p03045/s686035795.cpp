#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class UnionFind {
    int n;
    vector<int> par, rank;

public:
    UnionFind(int N) : n(N), par(N, -1), rank(N) {}
    int root(int i) {
        if (par[i] < 0) return i;
        return par[i] = root(par[i]);
    }
    bool same(int i, int j) { return root(i) == root(j); }
    void unite(int i, int j) {
        i = root(i);
        j = root(j);
        if (i == j) return;
        if (rank[i] <= rank[j]) {
            par[i] = j;
            if (rank[i] == rank[j]) { rank[j]++; }
        } else {
            par[j] = i;
        }
    }
};

class Main {
    int N, M;
    vector<int> X, Y, Z;
    void input() {
        cin >> N >> M;
        X.resize(M);
        Y.resize(M);
        Z.resize(M);
        REP(i, M) {
            cin >> X[i] >> Y[i] >> Z[i];
            X[i]--;
            Y[i]--;
        }
    }
    void output() {
        UnionFind ufd(N);
        REP(i, M) { ufd.unite(X[i], Y[i]); }
        set<int> st;
        REP(i, N) { st.emplace(ufd.root(i)); }
        cout << st.size() << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
