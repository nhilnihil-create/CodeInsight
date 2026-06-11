#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int n, c, d[33][33], cnt[3][33];

int main()
{
    cin >> n >> c;
    
    for(int i = 1; i <= c; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> d[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            cnt[(i + j) % 3][a]++;
        }
    }
    
    int res = 1e9;
    for(int i = 1; i <= c; i++)
    {
        int sum1 = 0;
        rep(x, c + 1)
        {
            if(i == x) continue;
            sum1 += cnt[0][x] * d[x][i];
        }

        for(int j = 1; j <= c; j++)
        {
            if(i == j) continue;
            int sum2 = 0;
            rep(x, c + 1)
            {
                if(j == x) continue;
                sum2 += cnt[1][x] * d[x][j];
            }

            for(int k = 1; k <= c; k++)
            {
                if(i == k || j == k) continue;
                int sum3 = 0;
                rep(x, c + 1)
                {
                    if(k == x) continue;
                    sum3 += cnt[2][x] * d[x][k];
                }
               res = min(res, sum1 + sum2 + sum3);
            }
        }
    }
    cout << res << endl;

    return 0;
}