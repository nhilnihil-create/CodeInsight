#include <bits/stdc++.h>
using namespace std;
const int maxn=67108866;
int dp[maxn];
char str[200004];
int main()
{
    memset(dp,127,sizeof(dp));
    dp[0]=0;
    scanf("%s",str);
    int l=strlen(str),now=0,ans;
    for(int i=0;i<l;i++)
    {
        int num=str[i]-'a';
        now=now^(1<<num);
        int best=dp[now];
        for(int j=0;j<26;j++)
        {
            best=min(best,dp[now^(1<<j)]);
        }
        best++;
        dp[now]=min(dp[now],best);
        //printf("%d %d\n",i,best);
        ans=best;
    }
    printf("%d\n",ans);
    return 0;
}
