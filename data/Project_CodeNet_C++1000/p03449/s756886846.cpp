#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int n,a[105][105]={0},b[105][105]={0};
    scanf("%d",&n);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    b[1][1]=a[1][1];
    for(int i=1;i<=2;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1)
                b[i][j]=b[i][j-1]+a[i][j];
            else
                b[i][j]=max(b[i-1][j],b[i][j-1])+a[i][j];
            }
        }
    printf("%d\n",b[2][n]);
    return 0;
}