#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, MOD = 1e9 + 7;
vector<vector<char> > v;
void solve() {
    cin >> n >> m;
    v.resize(n);
    fill(v.begin(), v.end(), vector<char>(m));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    vector<vector<ll> > dp(n, vector<ll>(m, 0));
    dp[n - 1][m - 1] = 1;
    for (int j = m - 2; j >= 0; j--)
        dp[n - 1][j] = v[n - 1][j] == '.' ? dp[n - 1][j + 1] : 0;
    for (int i = n - 2; i >= 0; i--)
        dp[i][m - 1] = v[i][m - 1] == '.' ? dp[i + 1][m - 1] : 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            if (v[i][j] != '.')
                dp[i][j] = 0;
            else {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                dp[i][j] = dp[i][j] % MOD;
            }
        }
    }
    cout << dp[0][0] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}