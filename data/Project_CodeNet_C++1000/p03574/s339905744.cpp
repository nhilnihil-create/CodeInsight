#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define P 1000000007
#define inf 1e18
int main()
{
    ll i, n, j, m;
    cin >> n >> m;
    char s[60][60];

    for (i = 0; i < n + 3; i++)
    {
        for (j = 0; j < n + 3; j++)
        {
            s[i][j] = '?';
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            char p;
            cin >> p;
            s[i][j] = p;
        }
    }

    ll count[56][56];

    for (i = 0; i < 53; i++)
    {
        for (j = 0; j < 53; j++)
            count[i][j] = 0;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (s[i][j] == '.')
            {
                if (s[i - 1][j] == '#')
                {
                    count[i][j]++;
                }
                if (s[i + 1][j] == '#')
                {
                    count[i][j]++;
                }
                if (s[i][j + 1] == '#')
                {
                    count[i][j]++;
                }
                if (s[i][j - 1] == '#')
                {
                    count[i][j]++;
                }
                if (s[i - 1][j - 1] == '#')
                {
                    count[i][j]++;
                }
                if (s[i - 1][j + 1] == '#')
                {
                    count[i][j]++;
                }
                if (s[i + 1][j - 1] == '#')
                {
                    count[i][j]++;
                }
                if (s[i + 1][j + 1] == '#')
                {
                    count[i][j]++;
                }
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (s[i][j] == '#')
            {
                cout << s[i][j];
            }
            else
            {
                cout << count[i][j];
            }
        }
        cout << "\n";
    }

    return (0);
}