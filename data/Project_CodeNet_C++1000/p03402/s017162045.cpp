#include<iostream>
using namespace std;
const int sz=110;
int g[sz][sz];
main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(!a)
    {
        printf("1 1\n#\n");
        return 0;
    }
    if(!b)
    {
        printf("1 1\n.\n");
        return 0;
    }
    printf("100 100\n");
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)if(i<=50) g[i][j]=0;else g[i][j]=1;
    }
    a--,b--;
    for(int i=1;i<=50&&b;i+=2)for(int j=1;j<=100&&b;j+=2)g[i][j]=1,b--;
    for(int i=1;i<=50&&a;i+=2)for(int j=1;j<=100&&a;j+=2)g[101-i][j]=0,a--;
    for(int i=1;i<=100;i++,putchar('\n'))for(int j=1;j<=100;j++)printf("%c",g[i][j]?'#':'.');
    return 0;
}