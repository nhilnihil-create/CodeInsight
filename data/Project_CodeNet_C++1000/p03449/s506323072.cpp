#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>>
#include<stdlib.h>
#define MAX  100005
#define ll long long
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    int a[2][101],b[101]={0},i,j;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[0][i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[1][i]);
    }
    sum=sum+a[0][0]+a[1][n-1];
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n-1;j++)
        {
            b[i]=b[i]+a[1][j];
        }
        for(j=0;j<i;j++)
        {
            b[i]=b[i]+a[0][j+1];
        }
    }
    sort(b,b+(n-1),cmp);
    sum=sum+b[0];
    printf("%d\n",sum);
    return 0;
}