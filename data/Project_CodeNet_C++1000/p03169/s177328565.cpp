#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define sz(x) ((int)x.size())

int n;
long double dp[301][301][301] = {{{0.0L}}};

long double dfs(int c1, int c2, int c3)
{
    if(c1 == 1 && c2 == 0 && c3 == 0)
        return n;
    if(dp[c1][c2][c3] > 0.0L)
        return dp[c1][c2][c3];
    long double exp = 0.0L, den = (long double)(c1 + c2 + c3);
    if(c1 > 0)
        exp += dfs(c1-1, c2, c3)*(long double)c1/den;
    if(c2 > 0)
        exp += dfs(c1+1, c2-1, c3)*(long double)c2/den;
    if(c3 > 0)
        exp += dfs(c1, c2+1, c3-1)*(long double)c3/den;
    dp[c1][c2][c3] = exp + (n - den)/den + 1;
    return dp[c1][c2][c3];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 1)
            c1++;
        else if(x == 2)
            c2++;
        else
            c3++;
    }
    cout << setprecision(15) << dfs(c1, c2, c3) << endl;
}