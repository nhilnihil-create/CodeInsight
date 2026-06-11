#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> a(N, vector<int>(N, 0)), c(N, vector<int>(N + 1, 0));
    for (int i = 0, L, R; i < M; i++) {
        cin >> L >> R;
        a[L - 1][R - 1]++;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            c[i][j + 1] = c[i][j] + a[i][j];
        }
    }
    for (int i = 0, p, q; i < Q; i++) {
        cin >> p >> q;
        int s = 0;
        for (int j = p - 1; j < q; j++) {
            s += c[j][q] - c[j][p - 1];
        }
        cout << s << endl;
    }
}