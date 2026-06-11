#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

char table[60][60];

int main()
{
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            char x;
            cin >> x;
            if (x == '.')
                x = '0';
            table[i][j] = x;
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (table[i][j] == '#')
            {
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (table[k][l] == '#')
                            continue;
                        else
                        {
                            table[k][l] += 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cout << table[i][j];
        }
        cout << endl;
    }
    return 0;
}