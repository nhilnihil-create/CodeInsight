#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
int solve(int i, auto &arr, auto &dp) {
    if (~dp[i]) return dp[i];
    int minV = 1;
    for (auto &v : arr)
        if (i - v >= 0)
            minV = min(minV, solve(i - v, arr, dp));
    return dp[i] = !minV;
}
void marmot0814() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &v : arr)
        cin >> v;
    vector<int> dp(k + 1, -1); dp[0] = 0;
    if (solve(k, arr, dp))
        cout << "First\n";
    else
        cout << "Second\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}