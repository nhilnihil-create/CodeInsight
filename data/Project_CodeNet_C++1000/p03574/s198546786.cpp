#include <iostream>

using namespace std;

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};

int main()
{
    int w, h;
    cin >> h >> w;
    char mass[50][50];
    int ans[50][50];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> mass[i][j];
        }
    }

    // init
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans[i][j] = 0;
        }
    }

    // height
    for (int i = 0; i < h; i++)
    {
        // wide
        for (int j = 0; j < w; j++)
        {
            // mass
            for (int k = 0; k < 8; k++)
            {
                int nei_x = i + dx[k];
                int nei_y = j + dy[k];
                if (nei_x < 0 || h <= nei_x)
                    continue;
                if (nei_y < 0 || w <= nei_y)
                    continue;
                if (mass[nei_x][nei_y] == '#')
                {
                    ans[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (mass[i][j] == '#')
                cout << '#';
            else
                cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}