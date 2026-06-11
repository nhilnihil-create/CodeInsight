#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[2][N];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    int total[2][N];
    total[0][0] = A[0][0];
    for (int j = 1; j < N; j++) {
        total[0][j] = total[0][j - 1] + A[0][j];
    }
    total[1][0] = A[0][0] + A[1][0];
    for (int j = 1; j < N; j++) {
        total[1][j] = max(total[0][j], total[1][j - 1]) + A[1][j];
    }

    cout << total[1][N - 1] << endl;
}