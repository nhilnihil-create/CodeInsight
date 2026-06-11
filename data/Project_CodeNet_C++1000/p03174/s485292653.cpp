#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
void marmot0814() {
    int n; cin >> n;
    vector<LL> dp(1 << n, 0); dp[0] = 1;
    for (int i = 0 ; i < n ; i++) {
        vector<LL> tmp(1 << n, 0);
        vector<int> arr(n);
        for (auto &v : arr)
            cin >> v;
        for (int S = 0 ; S < (1 << n) ; S++) {
            if (__builtin_popcount(S) != i + 1)
                continue;
            for (int j = 0 ; j < n ; j++) {
                if (arr[j] == 0) continue;
                if (((S >> j) & 1) == 0)
                    continue;
                (tmp[S] += dp[S ^ (1 << j)]) %= MOD;
            }
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