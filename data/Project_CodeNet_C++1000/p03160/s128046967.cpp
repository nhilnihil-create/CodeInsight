#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int mod = 998244353, maxn = 1e5+10;
int N, M;
int h[maxn], dp[maxn];

int main()
{
    memset(dp, 0x3f,sizeof(dp));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &h[i]);
    dp[1] = 0;
    for(int i = 2; i <= N; i++) {
        if(i > 1)
            dp[i] = min(dp[i], dp[i-1]+abs(h[i]-h[i-1]));
        if(i > 2)
            dp[i] = min(dp[i], dp[i-2]+abs(h[i]-h[i-2]));
    }
    printf("%d\n", dp[N]);
    return 0;
}
