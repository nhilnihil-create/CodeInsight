#include <iostream>
#include<algorithm>
#define MAX 502
using namespace std;

int N;
int T[MAX][MAX], D[MAX][MAX];

int compute(int p, int q) {
    return D[q][q] - D[p - 1][q];
}

int main() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            T[i][j] = 0;
            D[i][j] = 0;
        }
    }
    int M, Q, L, R, p, q;
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        cin >> L >> R;
        T[L][R]++;
    }
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = 0; j < MAX - 1; j++) {
            D[i + 1][j + 1] = D[i][j + 1] + D[i + 1][j] - D[i][j] + T[i + 1][j + 1];
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> p >> q;
        cout << compute(p, q) << endl;
    }
    return 0;
}