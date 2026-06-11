#include<bits/stdc++.h>
using namespace std;

int N,K;
char S[310],T[310];
int dp[310][310][310] = {0};
int ans = 0;

int main()
{
    scanf("%s %d",S + 1,&K);

    N = strlen(S + 1);
    if(N == 1)
    {
        printf("1\n");
        return 0;
    }
    if(N == 2)
    {
        if(K || S[1] == S[2])printf("2\n");
        else printf("1\n");
        return 0;
    }
    for(int i = 1; i <= N; i++)T[i] = S[i];
    reverse(T + 1,T + 1 + N);

    for(int i = 0; i <= K; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            for(int k = 1; k <= N; k++)
            {
                dp[j][k][i] = max(dp[j - 1][k][i],dp[j][k - 1][i]);
                if(S[j] == T[k])dp[j][k][i] = max(dp[j][k][i],dp[j - 1][k - 1][i] + 1);
                if(i != 0)dp[j][k][i] = max(dp[j][k][i],dp[j - 1][k - 1][i - 1] + 1);
                if(j + k == N)ans = max(ans,dp[j][k][i] * 2);
                if(j + k == N - 1)ans = max(ans,dp[j][k][i] * 2 + 1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
