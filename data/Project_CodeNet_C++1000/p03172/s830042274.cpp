#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
void marmot0814() {
    int n, k; cin >> n >> k;
    vector<LL> dp(k + 1, 0); dp[0] = 1;
    for (int i = 0 ; i < n ; i++) {
        LL v; cin >> v;
        LL sum = 0;
        vector<LL> tmp;
        for (int j = 0 ; j < v ; j++) {
            (sum += dp[j]) %= MOD;
            tmp.push_back(sum);
        }
        for (int j = v ; j <= k ; j++) {
            (sum += dp[j]) %= MOD;
            tmp.push_back(sum);
            (sum -= dp[j - v] - MOD) %= MOD;
        }
        dp = tmp;
    }
    cout << dp.back() << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}