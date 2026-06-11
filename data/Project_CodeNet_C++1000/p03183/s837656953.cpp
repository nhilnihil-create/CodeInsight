#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    // dp[i][j] = max value of first i blocks with weight <= j
    int n;
    cin >> n;
    using block = tuple<int, int, int, int>;
    vector<block> blocks;
    int max_w = 0;
    int max_s = 0;
    for (int i = 0; i < n; ++i) {
        int w, s, v;
        cin >> w >> s >> v;
 
        max_w = max(max_w, w);
        max_s = max(max_s, s);
        blocks.emplace_back(w + s, w, s, v);
    }
    sort(all(blocks));
 
    int cap = max_s + max_w;
    // now run the dp
    vector<vector<ll>> dp(n + 1, vector<ll>(cap + 1, 0LL));
 
    for (int i = 0; i < n; ++i) {
        int ws, w, s, v;
        tie(ws, w, s, v) = blocks[i];
        for (int j = 0; j <= cap; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j <= s && j + w <= cap) {
                dp[i + 1][j + w] = max(dp[i + 1][j + w], dp[i][j] + v);
            }
        }
    }
 	ll ans =0;
 	for(int j = 0;j<=cap;j++)
	 	ans = max(ans,dp[n][j]);
	cout << ans << '\n';
    return 0;
}