#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

int pref[405] = {0}, dp[405][405];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> pref[i], dp[i][i] = 0, pref[i] += pref[i-1];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j+i-1 <= n; j++)
        {
            int l = j, r = j+i-1;
            dp[l][r] = (1LL<<60);
            for(int k = l; k < r; k++)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + pref[r]-pref[l-1]);
        }
    cout << dp[1][n] << endl;
}