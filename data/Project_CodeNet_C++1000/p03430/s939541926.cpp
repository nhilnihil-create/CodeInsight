#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<string>

using namespace std;
typedef long long LL;

const int maxn=310;

int DP[maxn][maxn][maxn],v;
char str[maxn];

int Cal()
{
    int len=strlen(str);
    memset(DP,0,sizeof(DP));
    for(int i=0;i<len;i++) DP[i][i][0]=1;
    for(int i=len-2;i>=0;i--)
        for(int j=i+1;j<len;j++)
             for(int k=0;k<=v;k++)
             {
        if(str[j]==str[i]) DP[i][j][k]=DP[i+1][j-1][k]+2;
        else
        {
            DP[i][j][k]=max(DP[i+1][j][k],DP[i][j-1][k]);
            if(k)  DP[i][j][k]=max(DP[i+1][j-1][k-1]+2,DP[i][j][k]);
        }
             }
    int ans=0;
    for(int i=0;i<=v;i++) ans=max(ans,DP[0][len-1][i]);
    return ans;
}

int main()
{
    scanf("%s",&str);
    scanf("%d",&v);
    printf("%d",Cal());
    return 0;
}
