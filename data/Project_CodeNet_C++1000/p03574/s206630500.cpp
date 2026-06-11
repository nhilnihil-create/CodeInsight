#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
char s[51][51];
int cnt = 0;
int h, w;
int main()
{
    cin >> h >> w;
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> s[j][i];
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cnt = 0;
            if (s[j][i] == '#')
            {
                cout << "#";
            }
            else
            {
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        int X = j + x;
                        int Y = i + y;
                        if (0 <= X && X < w && 0 <= Y && Y < h)
                        {
                            if (s[X][Y] == '#')
                            {
                                cnt++;
                            }
                        }
                    }
                }
                cout << cnt;
            }
        }
        cout << endl;
    }
    return 0;
}
