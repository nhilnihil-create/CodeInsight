#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;

    int sLength = s.length();
    int tLength = t.length();

    vector<vector<int>> dp(sLength + 1, vector<int>(tLength + 1));

    for(int i = 1; i <= sLength; i++)
    {
        for(int j = 1; j <= tLength; j++)
        {
            if(s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;        
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }     
        }
    }

    string ans;
    int i = sLength, j = tLength;
    
    while(i >= 1 && j >= 1)
    {
        if(s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            i--;
            j--;
        }
        else
        {
            if(max(dp[i - 1][j], dp[i][j - 1]) == dp[i - 1][j])
            {
                i--;
            }
            else
            {
                j--;
            }     
        }

        //cout << i << " " << j << " " << ans << "\n";      
    }

    reverse(ans.begin(), ans.end());

    cout << ans;

    // for(int i = 0; i <= sLength; i++)
    // {
    //     for(int j = 0; j <= tLength; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    // cout << dp[sLength][tLength];

    return 0;
}