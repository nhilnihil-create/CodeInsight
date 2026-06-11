#include <bits/stdc++.h>

using namespace std;

int r, d, x;
int dp[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> d >> x;

    dp[1] = r * x - d;
    cout << dp[1] << "\n";
    for(int i = 2; i <= 10; i++)
    {
        dp[i] = r * dp[i - 1] - d;
        cout << dp[i] << "\n";
    }

    return 0;
}
