#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
LL solve(int L, int R, auto &dp, auto &arr, auto &preS) {
    if (~dp[L][R]) return dp[L][R];
    if (R - L <= 1) return dp[L][R] = 0;
    dp[L][R] = INF;
    for (int i = L + 1 ; i < R ; i++) {
        LL l = solve(L, i, dp, arr, preS);
        LL r = solve(i, R, dp, arr, preS);
        dp[L][R] = min(dp[L][R], l + r + preS[R] - preS[L]);
    }
    return dp[L][R];
}
void marmot0814() {
    int n; cin >> n;
    vector<LL> arr(n), preS{0};
    for (auto &v : arr)
        cin >> v, preS.push_back(preS.back() + v);
    vector<vector<LL>> dp(n + 1, vector<LL>(n + 1, -1));
    cout << solve(0, n, dp, arr, preS) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}