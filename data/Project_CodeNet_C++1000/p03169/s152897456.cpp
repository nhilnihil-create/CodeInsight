#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef double ll;

const unsigned int MAX = (ll)1002;
ll dp[301][301][301];
ll func(int z, int a, int b, int c, int n, int s)
{
    if (z == n)
    {
        return 0;
    }
    if (a < 0 || b < 0 || c < 0)
    {
        return 0;
    }
    if (a + b + c > n)
    {
        return 0;
    }
    if (dp[a][b][c] != -1)
    {
        return dp[a][b][c];
    }
    else
    {
        return dp[a][b][c] = (1.0 + ((ll)a) * func(z + 1, a - 1, b, c, n, s - 1) / n + ((ll)b) * func(z, a + 1, b - 1, c, n, s - 1) / n + ((ll)c) * func(z, a, b + 1, c - 1, n, s - 1) / n) / (((ll)n - z) / n);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    int s = 0;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int x = 0; x < n; x++)
    {
        cin >> ar[x];
        if (ar[x] == 1)
        {
            c1++;
        }
        else if (ar[x] == 2)
        {
            c2++;
        }
        else if (ar[x] == 3)
        {
            c3++;
        }
        s += ar[x];
    }
    for (int a = 0; a < 301; a++)
    {
        for (int b = 0; b < 301; b++)
        {
            for (int c = 0; c < 301; c++)
            {
                dp[a][b][c] = -1;
            }
        }
    }
    func(0, c1, c2, c3, n, s);
    cout << setprecision(12) << dp[c1][c2][c3] << endl;
}