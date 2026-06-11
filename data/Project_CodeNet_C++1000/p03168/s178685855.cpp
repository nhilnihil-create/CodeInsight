#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
const int MAXV = 1e5 + 5;
void marmot0814() {
    int n; cin >> n;
    vector<double> dp(n + 1, 0); dp[0] = 1;
    for (int i = 0 ; i < n ; i++) {
        double v; cin >> v;
        for (int j = n ; j >= 1 ; j--)
            dp[j] = dp[j] * (1 - v) + dp[j - 1] * v;
        dp[0] *= (1 - v);
    }
    double sum = 0;
    for (int i = 0 ; i <= n ; i++) {
        if (i * 2 > n)
            sum += dp[i];
    }
    cout << fixed << setprecision(10) << sum << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}