#include<bits/stdc++.h>
#define maxn 5005
using namespace std;
typedef long long LL;
int n,a[maxn];
LL A,B;
LL f[maxn][maxn];
int main()  {
    scanf("%d%lld%lld",&n,&A,&B);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for (int i=1;i<=n;++i)  {
        for (int j=i-1,c=0;~j;--j)
            if (a[j]<a[i])
                // cout<<i<<" <- "<<j<<endl,
                f[i][i]=min(f[i][i],f[j][j]+(i-j-1-c)*B+c*A);
            else    ++c;
        for (int j=0;j<i;++j)
            f[i][j]=f[i-1][j]+B;
        // for (int j=0;j<=i;++j)
        //     printf("f[%d][%d]=%lld\n",i,j,f[i][j]);
    }
    LL ans=1LL<<62;
    for (int i=1;i<=n;++i)
        ans=min(ans,f[n][i]);
    printf("%lld\n",ans);
    return 0;
}