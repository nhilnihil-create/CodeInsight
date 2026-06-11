#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
const int mod = 998244353, maxn = 1e5+10;
int N, M, K;
vector<int> G[maxn];
int dp[maxn];
void dfs(int x)
{
    for(int i : G[x])
    {
        if(!dp[i])
            dfs(i);
        dp[x] = max(dp[x], dp[i]+1);
    }
}
int main()
{
    scanf("%d %d", &N, &M);
    int x, y;
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        G[y].push_back(x);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++)
        if(dp[i] == 0)
        {
            dfs(i);
            ans = max(ans, dp[i]);
        }
    printf("%d\n", ans);
    return 0;
}
