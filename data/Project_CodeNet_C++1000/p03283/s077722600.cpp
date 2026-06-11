#include<bits/stdc++.h>
#define MAXN 505
#define MAXM 200005
#define MAXQ 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dp[MAXN][MAXN],cnt[MAXN][MAXN];
int n,m,q;
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        cnt[l][r]++;
    }
    for(int i=1;i<=n;i++) dp[i][i]=cnt[i][i];
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            dp[i][j]=cnt[i][j]+dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
        }
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",dp[l][r]);
    }
    return 0;
}
