#include <iostream>
#include <vector>

using namespace std;


#define int_max 0x3f3f3f3f
#define int_min -0x3f3f3f3f

int main()
{
    int n;
    cin >> n;
    int cost = 0;
    int x;
    vector<int> costs(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        costs.at(i) = x;
    }

    vector<int> dp(n + 1, 0);

    dp[1] = 0;

    if (n > 2)
        dp[2] = min(abs(costs[3] - costs[1]), abs(costs[2] - costs[1]));
    else
        dp[2] = abs(costs[2] - costs[1]);

    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == 2)
            continue;

        int x = dp[i - 2] + abs(costs[i] - costs[i - 2]);
        int y = dp[i - 1] + abs(costs[i] - costs[i - 1]);
        dp[i] = min(x, y);
    }

    cout << dp[n] << endl;
}