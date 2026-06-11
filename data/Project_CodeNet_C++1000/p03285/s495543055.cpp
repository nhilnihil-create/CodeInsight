#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<bool> dp(n + 1);
    dp[4] = dp[7] = true;
    for(int i = 8; i <= n; i++)
    {
        if(dp[i - 4] || dp[i - 7])
            dp[i] = true;
        else
            dp[i] = false;
    }

    if(dp[n])
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
