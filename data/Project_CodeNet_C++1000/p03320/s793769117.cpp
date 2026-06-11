#include <stdio.h>
int sm(long long a)
{
    int ret=0;
    while (a)
    {
        ret+=a%10;
        a/=10;
    }
    return ret;
}
int main()
{
    long long cur=1;
    int k;
    scanf("%d",&k);
    while (k--)
    {
        printf("%lld\n",cur);
        long long best=-1;
        for (long long add=1;add<=1000000000000000;add*=10)
            if (best==-1||best*sm(cur+add)>(cur+add)*sm(best))
                best=cur+add;
        cur=best;
    }
    return 0;
}
