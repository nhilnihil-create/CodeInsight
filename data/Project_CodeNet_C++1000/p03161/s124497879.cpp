// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;
int n, k;
int ans = INT_MAX;
vector<int> hs;
#define rep(i, k, n) for (int i = k; i < (int)(n); i++)

int main()
{
    cin >> n >> k;

    rep(i, 0, n)
    {
        int h;
        cin >> h;
        hs.push_back(h);
    }
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(hs[0] - hs[1]);

    rep(i, 2, n)
    {
        int temp = INT_MAX;
        rep(j, i - k, i)
        {
            if (j < 0)
                continue;
            temp = min(temp, dp[j] + abs(hs[i] - hs[j]));
        }
        dp[i] = temp;
    }
    cout << dp[n - 1] << endl;
}