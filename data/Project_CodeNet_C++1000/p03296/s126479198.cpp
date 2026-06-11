#include <cstdio>

int n,a[105],Ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1,j;i<=n;i=j+1)
    {
        for(j=i;j<=n&&a[j+1]==a[i];++j);
        Ans+=(j-i+1)>>1;
    }
    printf("%d\n",Ans);
    return 0;
}