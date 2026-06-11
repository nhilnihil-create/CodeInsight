#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

const int max_time = 1e5;

int main() {
    int N, C; cin >> N >> C;
    
    vector<vector<int>> P(C, vector<int>(max_time + 2, 0));
    REP(i, 0, N) {
        int s, t, c; cin >> s >> t >> c; c--;
        P[c][s]++;
        P[c][t + 1]--;
    }

    REP(i, 0, C) {
        REP(j, 1, max_time + 1) {
            P[i][j] += P[i][j - 1];
        }
    }

    int ans = 0;
    REP(i, 1, max_time + 1) {
        int cnt = 0;
        REP(j, 0, C) {
            if (P[j][i]) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}