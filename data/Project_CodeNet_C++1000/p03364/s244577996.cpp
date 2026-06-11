#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(2*n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> s[i][j];
            s[i][j+n] = s[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        bool flag = true;
        for(int y = 0; y < n; y++)
        {
            for(int x = i; x < i+n; x++)
            {
                int z = x-i-y;
                if(z <= 0) continue;
                if(s[y][x] != s[y+z][x-z])
                {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) ans++;
    }
    cout << ans * n << endl;
}
