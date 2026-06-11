#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<int> B(M);
    vector<vector<int>> A(N, vector<int>(M));
    rep(i, M) { cin >> B[i]; }
    rep(i, N) {
        rep(j, M) { cin >> A[i][j]; }
    }
    int ans = 0;
    rep(i, N) {
        int k = 0;
        rep(j, M) { k += B[j] * A[i][j]; }
        if (0 < k + C) {
            ans++;
        }
    }
    cout << ans << endl;
}
