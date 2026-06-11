#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxN = 405;
const ll INF = 1e18 + 7;

vector<vector<ll>> dp(maxN, vector<ll>(maxN, INF)), ans(maxN, vector<ll>(maxN, INF));

int main()
{
    int n;
    cin >> n;
    vector<int> sl(n);
    for(auto &x : sl) cin >> x;
    for(int l = n - 1; l >= 0; l--) {
        for(int r = l; r < n; r++) {
            if(l == r) {
                dp[l][r] = sl[l];
                ans[l][r] = sl[l];
            }
            else {
                for(int in = l; in < r; in++) {
                    if(ans[l][r] > (dp[l][in] + dp[in + 1][r] + (in - l > 0 ? ans[l][in] : 0) + (r - (in + 1) > 0 ? ans[in + 1][r] : 0))) {
                        dp[l][r] = dp[l][in] + dp[in + 1][r];
                        ans[l][r] = dp[l][r] + (in - l > 0 ? ans[l][in] : 0) + (r - (in + 1) > 0 ? ans[in + 1][r] : 0);
                    }
                } 
            }
        }
    }
    cout << ans[0][n - 1];
    return 0;
}
