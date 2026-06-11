#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(k + 1);
   
    for(int i = 0; i < a[0]; i++)
    {
        dp[i] = 2;
    }

    for(int i = a[0]; i <= k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i - a[j] >= 0)
            {
                if(dp[i - a[j]] == 2)
                {
                    dp[i] = 1;
                    break;
                }
                else
                {
                    dp[i] = 2;
                }          
            }
            else
            {
                dp[i] = 2;
            }
        }
    }

    // for(int i = 0; i <= k; i++)
    // {
    //     cout << dp[i] << " ";
    // }

    // cout << "\n";
    
    if(dp[k] == 1)
    {
        cout << "First";
    }
    else
    {
        cout << "Second";
    }
    
    
    return 0;
}