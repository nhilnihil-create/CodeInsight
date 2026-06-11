#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w;
    cin >> h >> w;
    int d[h][w];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) d[i][j] = 0;
    string s[h];
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                if (i > 0)
                {
                    d[i - 1][j]++;
                    if (j > 0) d[i - 1][j - 1]++;
                    if (j < w - 1) d[i - 1][j + 1]++;
                }
                if (j > 0) d[i][j - 1]++;
                if (j < w - 1) d[i][j + 1]++;
                if (i < h - 1)
                {
                    d[i + 1][j]++;
                    if (j > 0) d[i + 1][j - 1]++;
                    if (j < w - 1) d[i + 1][j + 1]++;
                }
            }
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#') cout << '#';
            else cout << d[i][j];
        }
        cout << endl;
    }
    
}