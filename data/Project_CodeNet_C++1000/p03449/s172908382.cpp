#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;  cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    for (int i = 0; i < 2; ++i) for (int j = 0; j < N; ++j) cin >> A[i][j];

    vector<int> sum1(N + 1), sum2(N + 1);
    for (int i = 0; i < N; ++i) sum1[i + 1] = sum1[i] + A[0][i];
    for (int i = 0; i < N; ++i) sum2[i + 1] = sum2[i] + A[1][i];
    //DUMP(sum1, sum2);

    int ans = 0;
    for (int i = 1; i <= N; ++i) ans = max(ans, sum1[i] + sum2[N] - sum2[i - 1]);
    cout << ans << endl;
}
