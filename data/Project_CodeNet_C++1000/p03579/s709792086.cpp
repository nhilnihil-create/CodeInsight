#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10e5;
const int MAX_M = 10e5;

bool is_bipartite(int v, int N, vector<int> G[MAX_N + 1], int color[MAX_N + 1], int cur = 0) {
    color[v] = cur;
    for (int i = 0; i < G[v].size(); i++) {
        int nv = G[v][i];
        if (color[nv] != -1) {
            if (color[nv] == cur) return false;
            continue;
        }
        
        if (!is_bipartite(nv, N, G, color, 1 - cur)) return false;
    }
    return true;
}

int main() {
    // input
    int N, M, A[MAX_M], B[MAX_M];
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> A[i] >> B[i];

    // make graph
    vector<int> G[MAX_N + 1];
    for (int i = 0; i < M; i++) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // initialize color
    int color[MAX_N + 1];
    for (int i = 1; i <= N; i++) color[i] = -1;

    if (is_bipartite(1, N, G, color)) {
        int num_white = 0, num_black = 0;
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0) num_white++;
            else num_black++;
        }
        long long ans = 1LL * num_white * num_black - M;
        cout << ans << endl;
    } else {
        long long ans = 1LL * N * (N - 1) / 2 - M;
        cout << ans << endl;
    }
    return 0;
}