#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL k;

LL gsum(LL a)
{
    return a==0?0:a%10+gsum(a/10);
}

int main()
{
    while (scanf("%lld",&k)!=EOF)
    {
        LL ans=1,p=1;
        while (k--)
        {
            printf("%lld\n", ans);
            LL ans1=ans+p;
            LL ans2=ans+p*10;
            if (gsum(ans1)*ans2>=ans1*gsum(ans2)) { ans=ans1; }
            else { ans=ans2; p*=10; }
        }
    }
    return 0;
}
