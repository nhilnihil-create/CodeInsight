#include <iostream>
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long
#define maxn 0x3f3f3f3f
int a[5][105];
int main()
{
    memset(a,0,sizeof(a));
    int N;
    scanf("%d",&N);
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    a[2][1]+=a[1][1];
    for(int j=2;j<=N;j++)
    {
        a[1][j]+=a[1][j-1];
    }
    for(int j=2;j<=N;j++)
    {
        a[2][j]+=max(a[1][j],a[2][j-1]);
    }
    printf("%d\n",a[2][N]);
    return 0;
}