#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int A[2][N];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) cin >> A[i][j];
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i > j) cnt += A[0][j];
            else if (i == j) cnt += A[0][j] + A[1][j];
            else cnt += A[1][j];
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}