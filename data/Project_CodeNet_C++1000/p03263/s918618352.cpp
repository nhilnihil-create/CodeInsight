#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int h, w, grid[505][505];

int main()
{
    cin >> h >> w;
    rep(i, h) rep(j, w) cin >> grid[i][j];
    
    int res[303030][4], cnt = 0;
    rep(i, h)
    {
        rep(j, w - 1)
        {
            if(grid[i][j] % 2 == 1)
            {
                grid[i][j + 1]++;
                res[cnt][0] = i + 1; res[cnt][1] = j + 1; res[cnt][2] = i + 1; res[cnt][3] = j + 2;
                cnt++;
            }
        }
    }
    rep(i, h - 1)
    {
        if(grid[i][w - 1] % 2 == 1)
        {
            grid[i + 1][w - 1]++;
            res[cnt][0] = i + 1; res[cnt][1] = w; res[cnt][2] = i + 2; res[cnt][3] = w;
            cnt++;
        }
    }

    cout << cnt << endl;
    rep(i, cnt)
    {
        rep(j, 4)
        {
            cout << res[i][j] << ((j == 3)? "\n" : " ");
        }
    }
    
    
    return 0;
}