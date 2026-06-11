#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int mod = 998244353, maxn = 1e5+10;
int N, M, K;
int a[maxn], b[maxn], c[maxn], dp[maxn][3];

int main()
{
    memset(dp, 0x3f,sizeof(dp));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= N; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2])+a[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2])+b[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1])+c[i];
    }
    printf("%d\n", max(dp[N][0], max(dp[N][1], dp[N][2])));
    return 0;
}
