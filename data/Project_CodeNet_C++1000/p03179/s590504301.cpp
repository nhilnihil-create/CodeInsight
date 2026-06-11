#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;

void add_self(int &a, int b)
{
    a += b;

    if(a >= mod)
        a -= mod;
}

int dif(int x)
{
    if(x < 0)
        x += mod;

    return x;
}

int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    vector<int>dp(n + 1);

    dp[1] = 1;
    for(int l = 2; l <= n; l++)
    {
        vector<int>new_dp(n + 1);

        for(int i = 1; i < l; i++)
            add_self(dp[i], dp[i - 1]);

        for(int b = 1; b <= l; b++)
        {
            int L, R;

            if(s[l - 2] == '<')
            {
                L = 1;
                R = b - 1;
            }
            else
            {
                L = b;
                R = l - 1;
            }

            if(L <= R)
                add_self(new_dp[b], dif(dp[R] - dp[L - 1]));
        }

        dp = new_dp;
    }

    int answer = 0;
    for(int i = 1; i <= n; i++)
        add_self(answer, dp[i]);

    cout << answer;

    return 0;
}
