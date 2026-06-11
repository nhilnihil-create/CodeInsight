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
    string s; cin >> s;
    vector<LL> dp(n + 1, 0); dp[1] = 1;
    for (int i = 2 ; i <= n ; i++) {
        vector<LL> tmp(n + 1, 0);
        if (s[i - 2] == '<') {
            LL sum = 0;
            for (int j = 1 ; j <= i ; j++) {
                tmp[j] = sum;
                (sum += dp[j]) %= MOD;
            }
        } else {
            LL sum = 0;
            for (int j = i ; j >= 1 ; j--) {
                (sum += dp[j]) %= MOD;
                tmp[j] = sum;
            }
        }
        dp = tmp;
    }
    LL sum = 0;
    for (int i = 1 ; i <= n ; i++)
        (sum += dp[i]) %= MOD;
    cout << sum << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}