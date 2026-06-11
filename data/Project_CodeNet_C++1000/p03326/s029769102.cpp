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
    int N, M;
    cin >> N >> M;
    vector<lint> A(N), B(N), C(N);
    rep(i, N) cin >> A[i] >> B[i] >> C[i];
    
    lint ans = 0;
    rep(bit, 8) {
        vector<pair<lint, int>> S(N);
        rep(i, N) {
            lint res = 0;
            if (bit & 1) res -= A[i];
            else res += A[i];
            if (bit & 2) res -= B[i];
            else res += B[i];
            if (bit & 4) res -= C[i];
            else res += C[i];
            S[i] = pair<lint, int>{res, i};
        }
        sort(S.rbegin(), S.rend());
        lint A_res = 0, B_res = 0, C_res = 0;
        rep(i, M) {
            A_res += A[S[i].second];
            B_res += B[S[i].second];
            C_res += C[S[i].second];
        }
        ans = max(ans, abs(A_res) + abs(B_res) + abs(C_res));
    }
    cout << ans << "\n";
    return 0;
}
