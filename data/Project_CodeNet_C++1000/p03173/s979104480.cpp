#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 405;
const ll INF = 1e18 + 5;

ll v[MAX], dp[MAX][MAX];

ll sum(int L, int R)
{
    return v[R] - v[L - 1];
}

int main()
{
    int n;

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];

        v[i] += v[i - 1];
    }

    for(int L = n; L > 0; --L)
        for(int R = L; R <= n; ++R)
            if(L != R)
            {
                dp[L][R] = INF;
                for(int i = L; i < R; ++i)
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i + 1][R] + sum(L, R));
            }

    cout << dp[1][n];

    return 0;
}
