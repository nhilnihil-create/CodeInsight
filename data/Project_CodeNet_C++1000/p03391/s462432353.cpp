#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n;
int main()
{
    bool tf=true;
    LL ans=0,lalal=(1<<30);
    scanf("%lld",&n);
    for (LL u=1;u<=n;u++)
    {
        LL a,b;
        scanf("%lld%lld",&a,&b);
        if (a!=b) tf=false;
        ans=ans+a;
        if (a>b) lalal=min(lalal,b);
    }
    if (tf) printf("0");
    else printf("%lld\n",ans-lalal);
    return 0;
}