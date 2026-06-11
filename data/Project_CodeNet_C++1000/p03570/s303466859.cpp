#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000009
typedef long long ll;

using namespace std;
char a[200010];
int sum[200010];
int dp[(1<<26)+1];
int main()
{
    cin >> a;
    int len = strlen(a);
    sum[0] = 0;
    for(int i = 1; i <= len; i++)sum[i] = sum[i-1]^(1<<(a[i-1]-'a'));
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    int ans;
    for(int i = 0; i < len; i++)
    {
        int best = dp[sum[i+1]];
        for(int j = 0; j < 26; j++)
        {
            best = min(best, dp[sum[i+1]^(1<<j)]);
        }
        best++;
        dp[sum[i+1]] = min(dp[sum[i+1]], best);
        ans = best;
    }
    cout << ans << endl;
    return 0;
}