#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    
    //孤立してる黒マスがあるか探す
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    int ans = true;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if(s[i][j] == '#')
            {
                bool alone = true;
                for (int k = 0; k < 4; k++)
                {
                    int sx = dx[k] + j;
                    int sy = dy[k] + i;
                    
                    if(0 <= sx && sx < w && 0 <= sy && sy < h)
                    {
                        if(s[sy][sx] == '#')alone = false;
                    }
                }
                if(alone)ans = false;
            }
        }
    }
    
    cout << (ans ? "Yes" : "No") << endl;
}