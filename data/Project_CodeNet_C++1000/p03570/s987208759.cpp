#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    string s;
    cin >> s;
    int n = s.size();
    int cur = 0;
    vector<int> dp(n + 1, INF);
    vector<int> mn(1 << 26, INF);
    dp[0] = 0;
    mn[0] = 0;
    for (int i = 0; i < n; i++) {
        cur ^= 1 << (s[i] - 'a');
        dp[i + 1] = min(dp[i + 1], mn[cur] + 1);
        for (int c = 0; c < 26; c++) {
            int nxt = cur ^ (1 << c);
            dp[i + 1] = min(dp[i + 1], mn[nxt] + 1);
        }
        mn[cur] = min(mn[cur], dp[i + 1]);
    }
    cout << dp[n] << endl;
    return 0;
}