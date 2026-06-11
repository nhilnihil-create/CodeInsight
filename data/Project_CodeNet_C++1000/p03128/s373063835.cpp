#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
    if (a < b) a = b;
}

int cnt[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};

signed main() {
    int n, m;
    cin >> n >> m;
    int a[m];
    rep(i, m) {
        cin >> a[i];
        a[i]--;
    }
    sort(a, a + m);
    reverse(a, a + m);
    int dp[n + 1];
    fill(dp, dp + n + 1, -INF);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - cnt[a[j]] < 0) continue;
            chmax(dp[i], dp[i - cnt[a[j]]] + 1);
        }
    }
    string ans;
    int i = n;
    while (i > 0) {
        for (int j = 0; j < m; j++) {
            if (i - cnt[a[j]] < 0) continue;
            if (dp[i] == dp[i - cnt[a[j]]] + 1) {
                ans.push_back(a[j] + '1');
                i -= cnt[a[j]];
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}