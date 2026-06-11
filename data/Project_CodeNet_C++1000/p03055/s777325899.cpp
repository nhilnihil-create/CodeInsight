#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

vector<vector<int>> G;
int mxd = 0;
int t = 0;

void dfs(int d, int cur, int pre) {
    if(mxd < d) {
        mxd = d;
        t = cur;
    }
    for(auto p : G[cur]) if(p != pre) dfs(d+1, p, cur);
}

int Dia() {
    dfs(0, 0, 0);
    mxd = 0;
    dfs(0, t, t);
    return mxd;
}

int main() {
    int N; cin >> N;
    G.resize(N);
    rep(i, 0, N-1) {
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    cout << (Dia() % 3 != 1 ? "First" : "Second") << '\n';
    return 0;
}
