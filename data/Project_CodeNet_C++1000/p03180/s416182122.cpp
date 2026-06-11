#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 3005
#define M 1000000007

ll arr[20][20], dp[1 << 17], cost[1 << 17];
int n;

void upd(int i, int om, int mask, int gm)
{
    if(i > n){
    dp[mask] = max(dp[mask], dp[om] + cost[gm]);
    return;
    }
    dp[mask] = max(dp[mask], dp[om] + cost[gm]);
    upd(i + 1, om, mask, gm);
    if(((om >> (i - 1)) & 1) == 0)
        upd(i + 1, om, mask | (1 << (i - 1)), gm | (1 << (i - 1)));
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < (1 << n); i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if((i >> (j - 1)) & 1)
            {
                for(int k = j + 1; k <= n; k++)
                    if((i >> (k - 1)) & 1)
                        cost[i] += arr[j][k];
            }
        }
    }
    for(int i = 0; i < (1 << n); i++)
    {
        upd(1, i, i, 0);
    }
    cout << dp[(1 << n) - 1] << endl;
}

