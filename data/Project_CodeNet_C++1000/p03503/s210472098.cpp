#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10)), P(N, vector<int>(11));
    rep(i, N) rep(j, 10) cin >> F[i][j];
    rep(i, N) rep(j, 11) cin >> P[i][j];
    
    int ans = -2e9;
    REP(bit, (1 << 10)) {
        vector<int> S;
        rep(i, 10) {
            if (bit & (1 << i)) S.push_back(i);
        }
        int res = 0;
        rep(i, N) {
            int cnt = 0;
            for (int n : S) {
                if (F[i][n]) ++cnt;
            }
            res += P[i][cnt];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
