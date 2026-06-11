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
    vector<ll> num;

public:
    UnionFind(int N) : n(N), par(N, -1), rank(N), num(N, 1) {}
    int root(int i) {
        if (par[i] < 0) return i;
        return par[i] = root(par[i]);
    }
    bool same(int i, int j) { return root(i) == root(j); }
    void unite(int i, int j) {
        i = root(i);
        j = root(j);
        if (i == j) return;
        num[i] += num[j];
        num[j] = num[i];
        if (rank[i] <= rank[j]) {
            par[i] = j;
            if (rank[i] == rank[j]) { rank[j]++; }
        } else {
            par[j] = i;
        }
    }
    ll num_group(int i) { return num[root(i)]; }
};

class Main {
    ll N, M;
    vector<int> A, B;
    void input() {
        cin >> N >> M;
        A.resize(M);
        B.resize(M);
        REP(i, M) {
            cin >> A[i] >> B[i];
            A[i]--;
            B[i]--;
        }
    }
    void output() {
        UnionFind ufd(N);
        vector<ll> res(M);
        res[M - 1] = N * (N - 1) / 2;
        FORR(i, 1, M) {
            res[i - 1] = res[i];
            if (ufd.same(A[i], B[i])) continue;
            res[i - 1] -= ufd.num_group(A[i]) * ufd.num_group(B[i]);
            ufd.unite(A[i], B[i]);
        }
        REP(i, M) { cout << res[i] << endl; }
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
