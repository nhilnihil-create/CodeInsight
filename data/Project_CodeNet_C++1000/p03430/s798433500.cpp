# include <bits/stdc++.h>
using namespace std;
const int maxn = 303;
int dp[maxn][maxn][maxn];
char s[maxn];
int main()
{
    int a;
    scanf("%s%d",s+1,&a);
    int len = strlen(s+1);
    for(int i=1; i<=len; ++i)
        for(int j=0; j<=a; ++j) dp[i][i][j] = 1;
    for(int j=1; j<=len; ++j)
    {
        for(int i=j-1; i>=1; --i)
        {
            for(int k=0; k<=a; ++k)
            {
                dp[i][j][k] = max(dp[i+1][j][k], dp[i][j-1][k]);//not change borders
                if(s[i]==s[j]) dp[i][j][k] = max(dp[i][j][k], dp[i+1][j-1][k]+2);//not change borders
                if(k) dp[i][j][k] = max(dp[i][j][k], max(dp[i][j][k], dp[i+1][j-1][k-1]+2));//change one border
            }
        }
    }
    printf("%d\n",dp[1][len][a]);
    return 0;
}
