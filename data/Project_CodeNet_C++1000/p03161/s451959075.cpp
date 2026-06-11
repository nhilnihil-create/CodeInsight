#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int mod = 998244353, maxn = 1e5+10;
int N, M, K;
int h[maxn], dp[maxn];

int main()
{
    memset(dp, 0x3f,sizeof(dp));
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        scanf("%d", &h[i]);
    dp[1] = 0;
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i && j <= K; j++)
            dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
    }
    printf("%d\n", dp[N]);
    return 0;
}
