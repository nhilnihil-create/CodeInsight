#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    REP(i, 0, N) cin >> S[i];

    int ans = 0;
    REP(a, 0, N) {
        bool symmetric = true;
        REP(i, 0, N) {
            REP(j, 0, N) {
                if (S[i][j] != S[(N + j - a) % N][(i + a) % N]) {
                    symmetric = false;
                }
            }
        }
        if (symmetric) ans += N;
    }
    cout << ans << endl;
    return 0;
}