#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

LL a,b,c,d;

LL gcd(LL x,LL y)
{
    if (!y) return x;
    else return gcd(y,x%y);
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        LL x=a%b,y=d%b;
        if (a<b) puts("No");
        else if (c>=b&&d>=b) puts("Yes");
        else if (d<b) puts("No");
        else if (x>c) puts("No");
        else
        {
            LL l=(b-x)%b,r=(c+b-x)%b,d=gcd(y,b);
            if (l<=r)
            {
                if (l-1>=d||r/d<(b-1)/d) puts("No");
                else puts("Yes");
                continue;
            }
            std::swap(l,r);
            l++;r--;
            if (l<=r&&(l/d!=r/d||l%d==0)) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}