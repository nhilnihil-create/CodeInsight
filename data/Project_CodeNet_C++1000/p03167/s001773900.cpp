#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w, mod = 1000000007;
    cin >> h >> w;
    string s[h];
    for (int i = 0; i < h; i++) cin >> s[i];
    int p[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 && j == 0) p[i][j] = 1;
            else if (s[i][j] == '#') p[i][j] = 0;
            else
            {
                if (i == 0) p[i][j] = p[i][j - 1];
                else if (j == 0) p[i][j] = p[i - 1][j];
                else p[i][j] = (p[i - 1][j] + p[i][j - 1]) % mod;
            }
        }
    }
    cout << p[h - 1][w - 1];
}