#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // H=行 W=列
    int H, W;
    int h, w;
    cin >> H >> W >> h >> w;

    vector<vector<int>> map(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) // 2
    {
        for (int j = 0; j < W; j++) // 1
        {
            if (i < h)
                map.at(i).at(j)++;
            if (j < w)
                map.at(i).at(j)++;
        }
    }

    int counter = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (map.at(i).at(j) == 0)
                counter++;
        }
    }

    // for (int i = 0; i < H; i++)
    // {
    //     for (int j = 0; j < W; j++)
    //     {
    //         cout << map.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    cout << counter << endl;
    return (0);
}