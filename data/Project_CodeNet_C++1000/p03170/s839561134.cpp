#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 2;
int n, k, nums[mxN];
bool dp[mxN];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    for (int i = 0; i <= k; i++)
    {
        bool ans = false;
        for (int j = 0; j < n; j++)
        {
            if (i - nums[j] >= 0)
            {
                ans = ans | (!dp[i - nums[j]]);
            }
        }
        dp[i] = ans;
    }

    if (dp[k] == 1)
    {
        cout << "First\n";
    }
    else
    {
        cout << "Second\n";
    }
    
}