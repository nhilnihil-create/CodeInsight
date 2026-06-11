#include <cstdio>

const int MAXN=200005;

int main()
{
    int n,x;
    int p[MAXN],ans[MAXN];

    for (int i=0;i<MAXN;++i)
    {
        p[i]=MAXN-1;
        ans[i]=0;
    }

    scanf("%d",&n);
    for (int i=0;i<n;++i)
    {
        scanf("%d",&x);
        if (i==0) ans[i]=1;
        else ans[i]=ans[i-1]+ans[p[x]]*(p[x]!=i-1);
        ans[i]%=1000000007;
        p[x]=i;
    }
    printf("%d",ans[n-1]);

    return 0;
}
