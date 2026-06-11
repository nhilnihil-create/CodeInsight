#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// ifstream fin("test.in");

// #define int_max 0x3f3f3f3f
// #define int_min -0x3f3f3f3f

int main()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> heights(n + 1, 0);
    vector<long long int> dp(n + 1, 0);
    long long int h;

    for (long long int i = 1; i <= n; i++)
    {
        cin >> h;
        heights.at(i) = h;
    }

    dp[1] = 0;
    dp[2] = abs(heights[2] - heights[1]);

    for (long long int i = 3; i <= n; i++)
    {
        long long int best = dp[i - 1] + abs(heights[i] - heights[i - 1]);

        for (long long int j = 2; j <= k && j < i; j++)
            best = min(best, dp[i - j] + abs(heights[i] - heights[i - j]));

        dp[i] = best;
    }

    cout << dp[n] << endl;
}