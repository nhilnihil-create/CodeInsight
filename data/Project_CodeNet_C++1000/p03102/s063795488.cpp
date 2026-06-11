#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M, C;
    cin >> N >> M >> C;

    int A[N][M], B[M];
    rep(i, M) cin >> B[i];
    rep(i, N) rep(j, M) cin >> A[i][j];

    int ans = 0;
    rep(i, N) {
        int sum = C;
        rep(j, M) sum += A[i][j] * B[j];
        if (sum > 0) ans++;
    }

    cout << ans << endl;

    return 0;
}