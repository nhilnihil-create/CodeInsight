#include<cstdio>
int n,f[200005];
long long ans=0;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&f[i]);
    int l=1,r=0,x=0,y=0;
    for (;l<=n;x=x^f[l],y=y-f[l],l++)
    {
        while ((x^f[r+1])==(y+f[r+1])&&r<n) ++r,x=x^f[r],y=y+f[r];
        ans=ans+(r-l+1);
    }
    printf("%lld\n",ans);
}