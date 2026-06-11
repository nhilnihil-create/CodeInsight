#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    
    vector<int> C(N);
    REP(i, 0, N) cin >> C[i];

    unordered_map<int, int> last;
    vector<int> next(N);
    for (int i = N - 1; i >= 0; i--) {
        if (last.count(C[i])) next[i] = last[C[i]];
        else next[i] = -1;
        last[C[i]] = i;
    }

    ll dp[N + 1] = {}; dp[N] = 1;
    for (int i = N - 1; i >= 0; i--) {
        dp[i] = (dp[i] + dp[i + 1]) % MOD;
        if (next[i] != -1 && (i < N - 1 && C[i] != C[i + 1])) dp[i] = (dp[i] + dp[next[i]]) % MOD;
    }

    cout << dp[0] << endl;

    return 0;
}