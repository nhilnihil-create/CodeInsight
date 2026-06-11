#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
const int mod = 1e9+7, maxn = 1e5+10;
int N, M, K;
int dp[1010][1010];
char maze[1010][1010];

int main()
{
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        scanf("%s", maze[i]+1);
    dp[1][1] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(maze[i][j] == '.')
            {
                if(dp[i-1][j])
                    dp[i][j] = (dp[i][j]+dp[i-1][j])%mod;
                if(dp[i][j-1])
                    dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
            }
    printf("%d\n", dp[N][M]);
    return 0;
}
