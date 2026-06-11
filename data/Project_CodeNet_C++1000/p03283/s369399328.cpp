#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> L(M), R(M);
    vector<int> p(Q), q(Q);
    for(int i = 0; i < M; i++) {
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }
    for(int i = 0; i < Q; i++) {
        cin >> p[i] >> q[i];
        p[i]--;
        q[i]--;
    }
    vector<vector<int>> a(N, vector<int>(N, 0));
    for(int i = 0; i < M; i++) {
        a[L[i]][R[i]] += 1;
    }
    vector<vector<int>> csum(N + 1, vector<int>(N + 1, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            csum[i + 1][j + 1] = csum[i][j + 1] + csum[i + 1][j] - csum[i][j] + a[i][j];
        }
    }
    for(int i = 0; i < Q; i++) {
        q[i]++;
        cout << csum[q[i]][q[i]] - csum[q[i]][p[i]] - csum[p[i]][q[i]] + csum[p[i]][p[i]] << endl;
    }
    return 0;
}