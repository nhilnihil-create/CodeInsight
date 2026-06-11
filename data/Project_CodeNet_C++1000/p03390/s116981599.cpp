#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c,d,sum;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        c=a*b;
        d=sqrt(c);
        if(d*(d+1)<c)
            sum=d*2-1;
        else if(d*d==c)
        {
            if(a==b)
                sum=(d-1)*2;
            else
                sum=(d-1)*2-1;
        }
        else
            sum=(d-1)*2;
        printf("%lld\n",sum);
    }
    return 0;
}