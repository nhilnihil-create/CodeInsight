#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int dx[4] = { -1, 0, 1,  0 };
int dy[4] = {  0, 1, 0, -1 };

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    for (int x = 0; x < h; ++x)
    {
        for (int y = 0; y < w; ++y)
        {
           
            if (s[x][y] == '#')
            {
                bool ok = false;
                for (int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

                    if (s[nx][ny] == '#') ok = true;
                }
                if (!ok)
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
