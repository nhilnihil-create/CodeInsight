#include <bits/stdc++.h>

using namespace std;
const int MAX = 22;
const int MOD = 1e9 + 7;

int mat[MAX][MAX], dp[1 << (MAX - 1)];

void add_self(int &a, int b)
{
    a += b;

    if(a >= MOD)
        a %= MOD;
}

int nrBits(int x)
{
    int cnt = 0;

    for(int i = 1; i <= x; i <<= 1)
        if(x & i)
            cnt++;

    return cnt;
}

int main()
{
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    dp[0] = 1;
    for(int mask = 0; mask < (1 << n); mask++)
    {
        int a = nrBits(mask);

        for(int b = 0; b < n; b++)
            if(mat[a][b] && !(mask & (1 << b)))
            {
                int mask2 = mask ^ (1 << b);

                add_self(dp[mask2], dp[mask]);
            }
    }

    cout << dp[(1 << n) - 1];

    return 0;
}
