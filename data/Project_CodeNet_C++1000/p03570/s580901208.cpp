#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
char str[MAXN];
int num[1<<26];
int dp[MAXN];
int sum;
int main()
{
    scanf("%s", str);
    memset(num, 0x3f, sizeof(num));
    memset(dp, 0x3f, sizeof(dp));
    num[0]=0;
    sum=0;
    int len=strlen(str);
    for(int i=0;i<len;++i)
    {
        int x=1<<(str[i]-'a');
        sum^=x;
        dp[i]=min(dp[i], num[sum]+1);
        for(int j=0;j<26;++j)
            dp[i]=min(dp[i], num[sum^(1<<j)]+1);
        num[sum]=min(num[sum], dp[i]);
    }
    printf("%d\n", dp[len-1]);
    return 0;
}
