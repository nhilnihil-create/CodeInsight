#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;

int main(void)
{
    int h, w;
    cin >> h >> w;
    h += 2;
    w += 2;

    vector<vector<char>> map(h, vector<char>(w));
    // init
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            map[i][j] = '.';
        }
    }
    // input
    for (int i = 1; i < h - 1; i++)
    {
        for (int j = 1; j < w - 1; j++)
        {
            cin >> map[i][j];
        }
    }

    // debug
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         printf("%c", map[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int i = 1; i < h - 1; i++)
    {
        for (int j = 1; j < w - 1; j++)
        {
            if (map[i][j] == '#')
            {
                if (!(map[i - 1][j] == '#' || map[i][j + 1] == '#' || map[i + 1][j] == '#' || map[i][j - 1] == '#'))
                {
                    cout << "No" << endl;
                    return (0);
                }
            }
        }
    }
    cout << "Yes" << endl;
    return (0);
}