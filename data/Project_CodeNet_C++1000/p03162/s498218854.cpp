#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

int n;
int a[100000+5], b[100000+5], c[100000+5];
int dp[100000+5][5];

int rec(int i, int prev)
{
    if(i >= n)
        return 0;
    if(dp[i][prev] != -1)
        return dp[i][prev];

    int ret = 0;
    if(prev == 0)
        ret = max(rec(i+1, 1)+b[i], rec(i+1, 2)+c[i]);
    else if(prev == 1)
        ret = max(rec(i+1, 0)+a[i], rec(i+1, 2)+c[i]);
    else if(prev == 2)
        ret = max(rec(i+1, 0)+a[i], rec(i+1, 1)+b[i]);

    return dp[i][prev] = ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i] >> b[i] >> c[i];
    cout << max({rec(1,0)+a[0], rec(1,1)+b[0], rec(1,2)+c[0]}) << endl;
}

