#include <bits/stdc++.h>
using namespace std;
#define MAXN    (200020)
#define inf     (0x3fffffff)
typedef priority_queue< int , vector<int> , greater<int> > spq;

int sl;
char s[MAXN];
int f[MAXN];
int dp[MAXN];
int m[67108864];

int main(void)
{
    int i, j;
    scanf("%s", s+1); sl = strlen(s+1);
    for(i = 1;i <= sl;++i)
    {
        f[i] = 1 << (s[i]-'a');
        f[i] ^= f[i-1];
    }
    for(i = 1;i < 67108864;++i) m[i] = inf;
    m[0] = 0;
    for(i = 1;i <= sl;++i)
    {
        int dpi = m[f[i]];
        for(j = 0;j < 26;++j)
            dpi = min(dpi, m[f[i]^(1<<j)]);
        dp[i] = dpi+1;
        m[f[i]] = min(m[f[i]], dp[i]);
    }
    printf("%d\n", dp[sl]);
    return 0;
}
