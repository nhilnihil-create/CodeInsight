#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> S(h);
    for (int i = 0; i < h; ++i)
    {
        cin >> S[i];
    }
    int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (S[i][j] == '.')
            {
                int bomb = 0;
                for (int k = 0; k < 8; ++k)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || ni > h - 1)
                    {
                        continue;
                    }
                    if (nj < 0 || nj > w - 1)
                    {
                        continue;
                    }
                    if (S[ni][nj] == '#')
                    {
                        ++bomb;
                    }
                }
                S[i].replace(j, 1, to_string(bomb));
            }
        }
    }
     for (int i = 0; i < h; ++i)
    {
        cout << S[i] << endl;
    }
}