#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long a,b,n;
int main()
{
    scanf("%lld%lld%lld",&n,&a,&b);
    if(a*b<n||a+b-1>n){printf("-1\n");return 0;}
    while(n>0)
    {
        long long x=min(a,n-b+1);
        for(long long i=1;i<=x;i++)
        printf("%d ",n-x+i);
        n-=x;
        b--;
    }
}