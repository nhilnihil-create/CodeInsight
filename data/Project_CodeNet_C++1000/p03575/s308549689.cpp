#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int N, M;

int par[55];  //親の番号

void init(int n) {
    for (int i = 0; i < n; ++i) par[i] = i;
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

    int ans = 0;
    rep(i, M) {
        init(N);
        rep(j, M) if (i != j) unite(A[j], B[j]);
        rep(j, N) if (!same(par[0], par[j])) {
            ++ans;
            break;
        }
    }
    cout << ans << endl;
}