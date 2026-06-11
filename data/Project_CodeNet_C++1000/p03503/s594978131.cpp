#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int N;  cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    for (int i = 0; i < N; ++i) for (int j = 0; j < 10; ++j) cin >> F[i][j];
    vector<vector<int>>  P(N, vector<int>(11));
    for (int i = 0; i < N; ++i) for (int j = 0; j <= 10; ++j) cin >> P[i][j];

    int ans = -INF;
    for (int i = 1; i < (1 << 10); ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            int cnt = 0;
            for (int k = 0; k < 10; ++k) {
                if (((i >> k) & 1) && (F[j][k] == 1)) ++cnt;
            }
            sum += P[j][cnt];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}
