#include<bits/stdc++.h>
using namespace std;
#define llong long long
const llong inf=0x3f3f3f3f3f3f3f3f;
int n,A,B;
int nu[5050];
llong f[5050][5050];
int main()
{
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=n;++i)scanf("%d",&nu[i]);
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    int x;
    for(int i=0;i<n;++i)
        for(int j=0;j<=n;++j)
        {
            if(f[i][j]==inf)continue;
            x=nu[i+1];
            if(j>x)f[i+1][j]=min(f[i+1][j],f[i][j]+B);
            else
            {
                f[i+1][x]=min(f[i+1][x],f[i][j]);
                f[i+1][j]=min(f[i+1][j],f[i][j]+A);
            }
        }
    llong ans=inf;
    for(int i=0;i<=n;++i)ans=min(ans,f[n][i]);
    printf("%lld\n",ans);
    return 0;
}
