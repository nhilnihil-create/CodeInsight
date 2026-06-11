#include <bits/stdc++.h>
using namespace std;

long long countOfSubarrays(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> bitPos(20, vector<int>(n));
    for (int bit = 0; bit < 20; bit++)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            bitPos[bit][i] = ((arr[i] >> bit) & 1);
        }
    }

    vector<vector<int>> dp(n, vector<int>(20));
    vector<int> maxRange(n, n);
    for (int bit = 0; bit < 20; bit++)
    {
        int lastIdx = n;
        
        for (int i = n - 1; i >= 0; i--)
        {
            if (bitPos[bit][i])
            {
                dp[i][bit] = lastIdx;
                lastIdx = i;
            }
            else
            {
                if (i == n - 1)
                    dp[i][bit] = n;
                else
                {
                    dp[i][bit] = dp[i + 1][bit];
                }
            }
            maxRange[i] = min(maxRange[i], dp[i][bit]);
        }
   }
    long long reqCnt = 0;
    for (int i = 0; i < n; i++)
    {
        reqCnt += maxRange[i] - i;
    }

   return reqCnt;
}

void solve()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long ans = countOfSubarrays(arr);
    cout << ans << endl;
}
int main()
{
    solve();
}
