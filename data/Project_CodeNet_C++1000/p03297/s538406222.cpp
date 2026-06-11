#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
bool judge()
{
    if(b>d) return false;
    if(a<b) return false;
    ll k=__gcd(b,d),s=a-(a-c)/k*k-k,t=10;
    while(t--)
    {
        if(s>c&&s<b) return false;
        s+=k;
    }
    return true;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(judge()) printf("Yes\n");
        else printf("No\n");
    }
}
