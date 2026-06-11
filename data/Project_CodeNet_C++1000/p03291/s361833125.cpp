#include <bits/stdc++.h>

#define REP(i, n) for(decltype(n) i = 0; i < n; i++)

#define ALL(c)   c.begin(), c.end()
#define SORT(c)  std::sort(ALL(c))
#define RSORT(c) std::sort(ALL(c), std::greater<decltype(c)::value_type>())

using namespace std;
using ll = long long;

const int MOD  = (int)1e9 + 7;
const int INF  = (int)1e9 + 1;
const ll  LINF = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.size();

    vector<vector<ll>> dp(N + 1, vector<ll>(4, 0));
    for(int i = N; i >= 0; --i) {
        for(int j = 3; j >= 0; --j) {
            if(i == N) {
                dp[i][j] = (j == 3 ? 1 : 0);
            }
            else {
                dp[i][j] = dp[i + 1][j] * (S[i] == '?' ? 3LL : 1LL);
                if(j < 3 && (S[i] == '?' || S[i] == "ABC"[j])) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
                dp[i][j] %= MOD;
            }
        }
    }

    std::cout << dp[0][0] << std::endl;

    return 0;
}
