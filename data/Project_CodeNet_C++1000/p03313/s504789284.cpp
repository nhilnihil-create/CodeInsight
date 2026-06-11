#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1 << 18;
const int LG = 18;
const int INF = 1e9 + 7;
pair <int, int> merge(pair <int, int> a, pair <int, int> b) {
    vector <int> v = {a.first, a.second, b.first, b.second};
    sort(v.begin(), v.end());
    return {v[2], v[3]};
}   
int a[N];
pair <int, int> dp[N][LG + 1];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); ++i) cin >> a[i];
    for (int i = 0; i < (1 << n); ++i) {
        dp[i][LG] = {a[i], -INF};
        for (int p = LG - 1; p >= 0; --p) {
            if ((i >> p) & 1) {
                dp[i][p] = merge(dp[i][p + 1], dp[i - (1 << p)][p + 1]);
            }   
            else {
                dp[i][p] = dp[i][p + 1];
            }
        }   
    }   
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        ans = max(ans, dp[i][0].first + dp[i][0].second);
        cout << ans << '\n';
    }   
}   