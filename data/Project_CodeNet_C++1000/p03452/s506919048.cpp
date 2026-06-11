#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(const vector< vector< pair<int,int> > > &g, vector<int> &x, int v, int p=-1) {
    bool res = true;
    for(auto u: g[v]) {
        if(u.first == p) continue;
        if(x[u.first] == numeric_limits<int>::min()) {
            x[u.first] = x[v] + u.second;
            res &= dfs(g, x, u.first, v);
        } else if(x[u.first] != x[v] + u.second) {
            res = false;
        }
    }
    return res;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    vector< vector< pair<int,int> > > g(N);
    while(M--) {
        int L, R;
        int64_t D;
        cin >> L >> R >> D;
        --L; --R;
        g[L].emplace_back(R, D);
        g[R].emplace_back(L, -D);
    }

    bool ans = true;
    vector<int> x(N, numeric_limits<int>::min());
    for(int i=0; i<N; i++) {
        if(x[i] == numeric_limits<int>::min()) {
            x[i] = 0;
            ans &= dfs(g, x, i);
        }
    }
    
    if(ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
