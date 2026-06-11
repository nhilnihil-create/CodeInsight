#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define INF INT_MAX
int a,b,T,flag=1,minn;
long long num;
int main()
{
    minn=INF;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d%d",&a,&b);
        num+=a;
        if(a>b)minn=min(minn,b);
        if(a!=b)flag=0;
    }
    if(flag)printf("0\n");
    else printf("%lld",num-minn);
}