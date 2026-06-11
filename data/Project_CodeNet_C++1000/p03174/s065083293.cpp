#include <bits/stdc++.h>

using namespace std;

int n;
bool arr[23][23] = {};
int M = 1000000007;
int memo[(1 << 21) + 1] = {};

int dp(int man, int rem_wmn)
{
    if (!rem_wmn)
        return 1;
    if (memo[rem_wmn])
        return memo[rem_wmn] - 1;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (!arr[man][n - 1 - i] || !(rem_wmn & (1 << i)))
            continue;
        num += dp(man + 1, rem_wmn ^ (1 << i));
        if (num >= M)
            num -= M;
    }
    memo[rem_wmn] = num + 1;
    return num;    
}

int main(void)
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        
    }
    int res;
    res = dp(0, (1 << n) - 1);
    printf("%d\n", res);
}