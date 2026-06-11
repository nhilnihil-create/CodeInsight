#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[110][110];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i < N; i++) A[0][i] += A[0][i - 1];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int sum = A[0][i];
        for (int j = i; j < N; j++) {
            sum += A[1][j];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}