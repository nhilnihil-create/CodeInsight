#include<bits/stdc++.h>

using namespace std;

#define pq priority_queue
#define MZ 1000000007

bool ok(long long x,long long a,long long b)
{
    long long lt,rt;
    if(x%2)
    {
        lt=x/2+1;
        rt=x/2+1;
    }
    else
    {
        lt=x/2;
        rt=x/2+1;
    }
    if(a<=lt)
        lt++;
    if(b<=rt)
        rt++;
    if((lt*rt)>=(a*b))
        return 0;
    if((a>lt) && (a<=x) && (b<(rt-a+lt)))
    {
        if(((a+1)*(rt-a+lt))>=(a*b))
            return 0;
    }
    if((b>rt) && (b<=x) && (a<(lt-b+rt)))
    {
        if(((b+1)*(lt-b+rt))>=(a*b))
            return 0;
    }
    lt++;
    rt--;
    if(lt==a)
        lt++;
    if(rt==b)
        rt--;
    if(lt*rt>=a*b)
        return 0;
    return 1;
}

int main()
{
    int q;
    long long a,b,l,r,mid;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%lld%lld",&a,&b);
        l=0;
        r=2LL*MZ;
        while(l!=r)
        {
            mid=(l+r+1)/2;
            if(ok(mid,a,b))
                l=mid;
            else
                r=mid-1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
