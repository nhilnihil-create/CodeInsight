#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N; cin >> N;

    int ans = 0, dp[N + 1] = {};
    REP(i, 0, N) {
        int p; cin >> p;
        dp[p] = dp[p - 1] + 1;
        ans = max(ans, dp[p]);
    }

    cout << N - ans << endl;
    return 0;
}