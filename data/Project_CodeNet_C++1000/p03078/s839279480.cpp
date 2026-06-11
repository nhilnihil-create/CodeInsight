#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<lint> A(X), B(Y), C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];
    
    vector<lint> D(X * Y);
    rep(i, X) rep(j, Y) D[i * Y + j] = A[i] + B[j];
    sort(D.rbegin(), D.rend());
    vector<int> cnt(Z, 0);
    rep(i, K) {
        lint ans = 0;
        rep(j, Z) {
            if (cnt[j] == X * Y) continue;
            ans = max(ans, D[cnt[j]] + C[j]);
        }
        cout << ans << "\n";
        rep(j, Z) {
            if (cnt[j] == X * Y) continue;
            if (D[cnt[j]] + C[j] == ans) {
                ++cnt[j];
                break;
            }
        }
    }
    return 0;
}
