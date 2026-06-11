#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int q;
typedef long long LL;
LL LLsqrt(LL x){
    LL L=0,R=1e9,mid,ans=-1;
    while (L<=R){
        mid=(L+R)>>1;
        if (mid*mid<=x)
            L=mid+1,ans=mid;
        else
            R=mid-1;
    }
    return ans;
}
int main()
{
    long long a,b;
    scanf("%d",&q);
    while(q--)
    {
        long long ans=0;
        scanf("%lld%lld",&a,&b);
        long long c=a*b-1;
        long long p=LLsqrt(c);
        ans+=2*p;
        if(a!=b)
            ans--;
            if(p)
        if(p==c/p)
            ans--;
        printf("%lld\n",ans);
    }
}
