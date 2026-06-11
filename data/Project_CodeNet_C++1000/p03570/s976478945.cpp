#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200003;
int n;char str[MaxN];
int f[MaxN],dp[MaxN];
map<int,int> mn;

int main() {
    scanf("%s",str+1);
    n=strlen(str+1);
    for (int i=1;i<=n;++i) {
        f[i]=f[i-1]^(1<<(str[i]-'a'));
    }
    for (int i=1;i<=n;++i) mn[f[i]]=0x7f7f7f7f;
    mn[0]=0;
    for (int i=1;i<=n;++i) {
        dp[i]=0x7f7f7f7f;
        if (mn.count(f[i])) dp[i]=min(dp[i],mn[f[i]]+1);
        for (int j=0;j<26;++j) {
            int t=f[i]^(1<<j);
            if (mn.count(t)) dp[i]=min(dp[i],mn[t]+1);
        }
        mn[f[i]]=min(mn[f[i]],dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}