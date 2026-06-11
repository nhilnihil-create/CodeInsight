#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define digit(a) to_string(a).size()
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;
int main(void)

{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, 0, n) cin >> v[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2));
    dp[0][0] = 0;
    dp[0][1] = -INF;
    rep(i, 0, n)
    {
        dp[i + 1][0] = max(dp[i][0] + v[i], dp[i][1] - v[i]);
        dp[i + 1][1] = max(dp[i][0] - v[i], dp[i][1] + v[i]);
    }
    cout << dp[n][0] << endl;
}
