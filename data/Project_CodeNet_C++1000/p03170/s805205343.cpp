#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(k + 1, vector<int>(n + 1));

    for(int i = 1; i < a[1]; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = 2;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[a[i]][j] = 1;
        }
    }

    for(int i = 1; i <= k; i++)
    {
        if(dp[i][1] != 0) continue;

        bool hasOne = false;
        
        for(int j = 1; j <= n; j++)
        {
            if(i - a[j] >= 1)
            {
                if(dp[i - a[j]][j] == 1)
                {
                    dp[i][j] = 2;
                }
                else
                {
                    dp[i][j] = 1;
                    hasOne = true;
                    break;
                }      
            }
            else
            {
                dp[i][j] = 2;
            }       
        }

        if(hasOne)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = 1;
            }
        }
    }

    // for(int i = 1; i <= k; i++)
    // {
    //     cout << i << ": ";
        
    //     for(int j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    if(dp[k][n] == 1)
    {
        cout << "First";
    }
    else
    {
        cout << "Second";
    }
    
     
    return 0;
}