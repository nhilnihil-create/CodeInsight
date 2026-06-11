#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> F(N);
    REP(i, N) {
        int bit = 0;
        REP(j, 10) {
            int d;
            cin >> d;
            bit += d << j;
        }
        F[i] = bit;
    }
    vector<vector<int>> P(N, vector<int>(11));
    REP(i, N) {
        REP(j, 11) {
            cin >> P[i][j];
        }
    }
    int ans = -1e9;
    for (int bit = 1; bit < 1 << 10; bit++) {
        int tmp = 0;
        REP(i, N) {
            int cnt = __builtin_popcount(F[i] & bit);
            tmp += P[i][cnt];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}