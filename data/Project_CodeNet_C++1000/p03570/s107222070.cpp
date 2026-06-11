#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=2e5+5;
char s[N];
int dp[1<<26],f[N];
int main()
{
    memset(dp,inf,sizeof(dp));
    scanf("%s",s+1);
    int n=strlen(s+1);
    dp[0]=0;
    int st=0;
    for(int i=1;i<=n;i++)
    {
        st^=1<<s[i]-'a';
        f[i]=dp[st]+1;
        for(int j=0;j<26;j++)
            f[i]=min(f[i],dp[st^(1<<j)]+1);
        dp[st]=min(dp[st],f[i]);
    }
    printf("%d\n",f[n]);
}
