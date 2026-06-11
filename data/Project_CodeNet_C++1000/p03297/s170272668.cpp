#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return gcd(b,a%b);
    }
}
ll com(ll a,ll b,ll m)
{
    ll temp=a%m;
    if((temp+m)%m>b)
    {
        b+=m;
    }
    ll ans=a+b-(temp+m)%m;
    return ans;
}
int main()
{
    int T;
    ll a,b,c,d;
    scanf("%d",&T);
    while(T--)
    {
        cin>>a>>b>>c>>d;
        if(b>a)
        {
            printf("No\n");
        }
        else if(d<b)
        {
            printf("No\n");
        }
        else
        {
            ll po=gcd(b,d);
            if(com(c-b+1,a%po,po)>=0)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}
