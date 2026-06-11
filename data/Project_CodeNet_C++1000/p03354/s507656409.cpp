#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

vector<int> par(100000);

int root(int x) {
    if (par[x] == x) return x;
    par[x] = root(par[x]);
    return par[x];
}

void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return;
    par[rx] = ry;
    return;
}

bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> p(N);
    rep(i, N) {
        cin >> p[i];
        --p[i];
    }
    vector<int> x(M), y(M);
    rep(i, M) {
        cin >> x[i] >> y[i];
        --x[i];
        --y[i];
    }
    
    rep(i, N) par[i] = i;
    rep(i, M) unite(x[i], y[i]);
    int cnt = 0;
    rep(i, N) if (same(i, p[i])) ++cnt;
    cout << cnt << endl;
    return 0;
}
