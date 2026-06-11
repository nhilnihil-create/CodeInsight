#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, K[3]; cin >> N >> K[0] >> K[1] >> K[2];

    vector<int> L(N);
    REP(i, 0, N) cin >> L[i];

    vector<vector<int>> cost(3, vector<int>(1 << N, 0));
    REP(i, 0, 3) {
        for (int bit = 1; bit < (1 << N); bit++) {
            int sum = 0, cnt = 0;
            REP(j, 0, N) if (bit & (1 << j)) {
                sum += L[j]; cnt++;
            }
            cost[i][bit] = abs(K[i] - sum) + 10 * (cnt - 1);
        }
    }

    int ans = 1 << 30;
    REP(i, 1, 1 << N) {
        REP(j, 1, 1 << N) {
            REP(k, 1, 1 << N) {
                if ((i & j) || (j & k) || (i & k)) continue;
                // cout << "###" << endl;
                // cout << bitset<8>(i) << " : " << cost[0][i] << endl;
                // cout << bitset<8>(j) << " : " << cost[1][j] << endl;
                // cout << bitset<8>(k) << " : " << cost[2][k] << endl;
                ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}