#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> l(N);
    rep(i, N) cin >> l[i];
    
    int ans = 100100100;
    rep(bit, 1 << (2 * N)) {
        vector<int> S(N);
        int co = bit;
        rep(i, N) {
            S[i] = co % 4;
            co /= 4;
        }
        int a = 0;
        int b = 0;
        int c = 0;
        int a_cnt = 0;
        int b_cnt = 0;
        int c_cnt = 0;
        rep(i, N) {
            if (S[i] == 1) {
                a += l[i];
                ++a_cnt;
            }
            if (S[i] == 2) {
                b += l[i];
                ++b_cnt;
            }
            if (S[i] == 3) {
                c += l[i];
                ++c_cnt;
            }
        }
        if (a == 0 || b == 0 || c == 0) continue;
        ans = min(ans, abs(A - a) + abs(B - b) + abs(C - c) + 10 * (a_cnt + b_cnt + c_cnt - 3));
    }
    cout << ans << endl;
    return 0;
}
