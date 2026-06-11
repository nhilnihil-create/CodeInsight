#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue> 
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
int n;
LL calc(LL a)
{
    int t=0;
    while(a) {t+=a%10; a/=10;}
    return t;
}

int main()
{
    scanf("%d",&n);
    LL x=0, m=1,x1,x2;
    for (int i=1; i<=n; i++)
    {
        x1=x+m; x2=x+m*10;
        if (x1*calc(x2)<=x2*calc(x1)) 
            x=x1;
        else
            {x=x2; m*=10;}
        printf("%lld\n",x);
    }
    return 0;
} 