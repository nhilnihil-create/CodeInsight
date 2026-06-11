#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll N, M;

int par[100005];  //親の番号
ll combi[100005];
ll res[100005];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        combi[i] = 1;
    }
}

int root(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = root(par[x]);
    }
}

bool same(int x, int y) { return root(x) == root(y); }

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;

    par[x] = y;
}

int main() {
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        --A[i];
        --B[i];
    }

    init(N);

    res[M - 1] = N * (N - 1) / 2;
    for (int i = M - 1; i > 0; --i) {
        if (!same(A[i], B[i])) {
            ll total = combi[root(A[i])] + combi[root(B[i])];
            res[i - 1] = res[i] - combi[root(A[i])] * combi[root(B[i])];
            unite(A[i], B[i]);
            combi[root(A[i])] = total;
        } else {
            res[i - 1] = res[i];
        }
    }
    rep(i, M) cout << res[i] << endl;
}