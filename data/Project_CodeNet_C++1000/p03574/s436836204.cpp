#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    char s[h + 1][w + 1];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == '.')
                s[i][j] = '0';
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int l = j - 1; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < h && l >= 0 && l < w && s[k][l] != '#')
                            s[k][l] += 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << s[i][j];
        }
        cout << endl;
    }
}
