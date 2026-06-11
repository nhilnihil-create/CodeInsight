#include<cstdio>
int vali[100100];
int a[1000][1000];
int main()
{
    for(int i=1;i*(i-1)/2<=100000;++i)
        vali[i*(i-1)/2]=i;
    int n;
    scanf("%d",&n);
    if(!vali[n])
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    printf("%d\n",vali[n]);
    int t=1,l=2*n/vali[n];
    for(int i=1;i<=vali[n];++i)
    {
        printf("%d ",l);
        for(int j=1;j<i;++j)
        {
            printf("%d ",a[j][i-1]);
            a[i][j]=a[j][i-1];
        }
        for(int j=i;j<=l;++j)
        {
            printf("%d ",t);
            a[i][j]=t++;
        }
        puts("");
    }
    return 0;
}
