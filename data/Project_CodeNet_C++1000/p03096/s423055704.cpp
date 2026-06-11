#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;
int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    vector<ll> dp(n, 0);
    vector<int> pos(1e6);
    for(int i = 0; i < 1e6; i++)
    {
        pos[i] = -1;
    }
    pos[c[0]] = 0;
    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
        dp[i] = dp[i-1];
        int bpos = pos[c[i]];
        if(bpos != -1 && bpos != i-1)
        {
            dp[i] = (dp[i] + dp[bpos]) % MOD;
        }
        pos[c[i]] = i;
    }
    cout << dp[n-1] << endl;
}
