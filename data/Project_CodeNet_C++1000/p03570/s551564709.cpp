#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int maxn = 1 << 26;
int dp[maxn], opt[200010], pre[200010], cnt[26], INF = 1e9;
char s [200010];

int main()
{
    for(int i = 1; i < maxn; i++)
        dp[i] = INF;
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++) {
        cnt[s[i] - 'a']++;
        for(int j = 0; j < 26; j++)
            pre[i] += (cnt[j] & 1 ) << j;
    }

    for(int i = 1; i <= n; i++) {
        int mn = INF;
        for(int j = 0; j < 26; j++) {
            int cur = dp[(1 << j) ^ pre[i]];
            mn = min(mn, cur);
        }
        mn = min(mn, dp[pre[i]]);
        opt[i] = mn + 1;
        dp[pre[i]] = min(dp[pre[i]], opt[i]);
    }
    printf("%d\n", opt[n]);
    return 0;
}
