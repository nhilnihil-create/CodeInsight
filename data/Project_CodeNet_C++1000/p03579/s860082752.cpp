#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<int> color;

bool dfs(int u, int c) {
    color[u] = c;
    for(int v : G[u]) {
        if(color[u] == color[v]) return false;
        if(color[v] == 0 && !dfs(v, -c)) return false;
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    color.resize(N, 0);
    for(int i=0; i<M; ++i) {
        int A, B;
        cin >> A >> B;
        --A; --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    if(dfs(0, 1)) {
        long long b = 0, w = 0;
        for(int i=0; i<N; ++i) {
            if(color[i] == 1) ++b;
            else ++w;
        }
        cout << b * w - M << endl;
    } else {
        cout << (long long)N * (N - 1) / 2 - M << endl;
    }
}