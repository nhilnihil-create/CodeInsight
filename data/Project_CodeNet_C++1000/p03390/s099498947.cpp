#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main()
{
    int q;scanf("%d",&q);
    while(q--)
    {
        scanf("%lld%lld",&a,&b);
        ll s=a*b,ans;
        ll t=sqrt(s);
        if(t*(t+1)<s) ans=2*(t-1)+1;
        else ans=2*(t-1);
        if(t*t==s&&a!=b) ans--;
        if(a*b==4) ans=1;
        printf("%lld\n",ans);
    }
}
