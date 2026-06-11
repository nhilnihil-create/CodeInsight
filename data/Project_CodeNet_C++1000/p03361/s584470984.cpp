#include <bits/stdc++.h>
using namespace std;

int H, W;
string s[60];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (s[i][j] == '#')
            {
                bool found = false;
                for (int k = 0; k < 4; k++)
                {
                    int x = j + dx[k];
                    int y = i + dy[k];
                    if (0 <= x && x < W && 0 <= y && y < H && s[y][x] == '#')
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}
