#include <bits/stdc++.h>
using namespace std;

int Section[550][550];

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        Section[L][R]++;
    }

    for (int i = 0; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            Section[i][j] += Section[i][j - 1];
        }
    }
    for (int j = 0; j <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            Section[i][j] += Section[i - 1][j];
        }
    }
    for (int i = 0; i < Q; ++i) {
        int p, q;
        cin >> p >> q;
        cout << Section[q][q] - Section[p - 1][q] - Section[q][p - 1] + Section[p - 1][p - 1] << endl;
    }
    return 0;
}