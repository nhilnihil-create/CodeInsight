#include <bits/stdc++.h>
#define WHOLE(v) (v).begin(), (v).end()
#define REV_WHOLE(v) (v).rbegin(), (v).rend()
using i64 = int64_t;
using namespace std;
int main() {
    string S;
    int coord[2];
    cin >> S >> coord[0] >> coord[1];
    S += "T";
    vector<int> F[2];
    int f = 0, t = -1;
    for(auto c : S) {
        if(c == 'T') {
            if(t < 0) {
                coord[0] -= f;
                t = 0;
            } else if(f > 0) {
                F[t].push_back(f);
            }
            f = 0;
            t = !t;
        } else {
            f++;
        }
    }
    bool ans = true;
    int N = S.size() + 10;
    for(int b = 0; b < 2; b++) {
        vector<bool> dp[2];
        dp[0] = vector<bool>(2 * N, false);
        dp[0][N] = true;
        for(int i = 0; i < F[b].size(); i++) {
            int f = F[b][i];
            dp[!(i & 1)] = vector<bool>(2 * N, false);
            for(int x = 0; x <= 2 * N; x++) {
                if(dp[i & 1][x]) {
                    dp[!(i & 1)][x + f] = dp[!(i & 1)][x - f] = true;
                }
            }
        }
        ans &= coord[b] + N >= 0 &&
            dp[F[b].size() & 1][coord[b] + N];
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}