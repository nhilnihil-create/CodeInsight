#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> a(h);

    for(int i = 0; i < h; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(h, vector<int>(w));

    for(int i = 0; i < h; i++)
    {
        if(a[i][0] != '#')
        {
            dp[i][0] = 1;
        }
        else
        {
            break;
        }     
    }

    for(int i = 0; i < w; i++)
    {
        if(a[0][i] != '#')
        {
            dp[0][i] = 1;
        }
        else
        {
            break;
        }       
    }

    for(int i = 1; i < h; i++)
    {
        for(int j = 1; j < w; j++)
        {
            if(a[i][j] != '#')
            {
                dp[i][j] = ((dp[i - 1][j] % M) + (dp[i][j - 1] % M)) % M;
            }      
        }
    }

    // for(int i = 0; i < h; i++)
    // {
    //     for(int j = 0; j < w; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    cout << dp[h - 1][w - 1];

    return 0;
}