#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int a,b,k;
    int c[200];
    scanf("%d%d%d",&a,&b,&k);
    int j=0;
    int d=min(a,b);
    for(int i=1;i<=d;i++)
    {
        if(a%i==0&&b%i==0)
        {
            c[j]=i;
            j++;
        }
    }
    sort(c,c+j,cmp);
    printf("%d\n",c[k-1]);
}
