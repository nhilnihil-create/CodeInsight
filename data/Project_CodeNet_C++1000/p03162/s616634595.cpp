#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(n+1, vector<int>(3));
    rep(i,n) {
        dp[i+1][0] = max(dp[i][1] + a[i], dp[i][2] + a[i]);
        dp[i+1][1] = max(dp[i][0] + b[i], dp[i][2] + b[i]);
        dp[i+1][2] = max(dp[i][1] + c[i], dp[i][0] + c[i]);
    }
    int ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
    cout << ans << endl;

    return 0;
}
