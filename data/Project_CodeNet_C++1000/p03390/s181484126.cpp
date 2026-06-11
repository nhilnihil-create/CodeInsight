#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll query,p,q,r;

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        scanf("%lld%lld",&p,&q);
        r=sqrt(p*q);
        if (r*r==p*q) r--;
        if (p==q) printf("%lld\n",(p-1)*2);
        else if (r*(r+1)<=p*q-1) printf("%lld\n",r*2-1);
        else printf("%lld\n",r*2-2);
    }
    return 0;
}
