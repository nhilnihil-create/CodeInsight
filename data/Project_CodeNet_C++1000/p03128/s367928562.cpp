#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    sort(A.begin(), A.end(), greater<int>());
    vector<int> B = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> C(M);
    for (int i = 0; i < M; i++) C[i] = B[A[i]];

    vector<int> dp(N+1, -N);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (i-C[j] < 0) continue;
            dp[i] = max(dp[i], dp[i-C[j]] + 1);
        }
    }

    int i = N;
    for (int j = 0; j < M; j++) {
        while (i-C[j] >= 0 && dp[i-C[j]] == dp[i]-1) {
            cout << A[j];
            i -= C[j];
        }
    }
    cout << "\n";
}