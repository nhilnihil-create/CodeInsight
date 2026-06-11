#include <iostream>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    char map[50][50] = {{0}};
    for (int count = 0; count < H; ++count)
    {
        cin >> map[count];
    }

    for (int x = 0; x < H; ++x)
    {
        for (int y = 0; y < W; ++y)
        {
            if (map[x][y] == '#')
            {
                if (x != 0 && map[x - 1][y] == '#')
                {
                }
                else if (x != 49 && map[x + 1][y] == '#')
                {
                }
                else if (y != 0 && map[x][y - 1] == '#')
                {
                }
                else if (y != 49 && map[x][y + 1] == '#')
                {
                }
                else
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