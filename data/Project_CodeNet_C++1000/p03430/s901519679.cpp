#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 315
#define ll long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
using namespace std;

int n, _k;
char s[maxn];

int dp[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
int DP(int a, int b, int k){
    if (a == n + 1 || !b) return 0;
    if (a >= b) return (a == b);
    if (vis[a][b][k]) return dp[a][b][k];
    vis[a][b][k] = 1;
    int& ans = dp[a][b][k];
    if (s[a] == s[b]) ans = max(ans, DP(a + 1, b - 1, k) + 2);
    if (k) ans = max(ans, DP(a + 1, b - 1, k - 1) + 2);
    ans = max(ans, DP(a + 1, b, k));
    ans = max(ans, DP(a, b - 1, k));
    return ans;
}

int main(){
    scanf("%s%d", s + 1, &_k);
    n = strlen(s + 1);
    printf("%d", DP(1, n, _k));
    return 0;
}