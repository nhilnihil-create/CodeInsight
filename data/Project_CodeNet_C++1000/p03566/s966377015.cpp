#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000007;

int T[102], V[20004], dp[20004][102];

int solve(int x, int y)
{
    if(y < 0 || y > V[x])
        return -inf;

    if(x == 0)
        return 0;

    if(dp[x][y] != -1)
        return dp[x][y];
    
    int ans = solve(x-1, y) + y * 4;
    ans = max(ans, solve(x-1, y-1) + (y-1) * 4 + 2);
    
    if(y != V[x])
    {
        ans = max(ans, solve(x-1, y+1) + y * 4 + 2);
        ans = max(ans, solve(x-1, y) + y * 4 + 1);
    }

    return dp[x][y] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> T[i];

    int k = 0;
    
    for(int i=1; i<=N; i++)
    {
        int v;
        cin >> v;

        while(T[i]--)
            V[++k] = v;
    }

    memset(dp, -1, sizeof(dp));

    cout << fixed << setprecision(6) << solve(k, 0) / 4.0 << "\n";
    return 0;
}
