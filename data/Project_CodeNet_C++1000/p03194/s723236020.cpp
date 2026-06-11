#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,p;
    scanf("%lld%lld",&n,&p);
    ll key=p;
    if(p==1){
        printf("1\n");
        return 0;
    }
    if(n==1){
        printf("%lld\n",p);
        return 0;
    }
    long long ans=1;
    for(ll i=2; i*i<=p;i++)
    {
        if(p%i==0)
        {
            ll cnt=0;
            while(p%i==0)
            {
                p/=i;
                cnt++;
            }
            if(cnt>=n) ans=(long long)ans*(long long)pow(i,cnt/n);
        }
    }
    printf("%lld\n",ans);
}
