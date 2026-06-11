#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000005

ll prime[MAXN];
ll vis[MAXN];
ll cnt;
ll n;
void isprime()
{
    cnt=0;
    for(int i=2; i<=MAXN; i++)
    {
        if(!vis[i])prime[cnt++]=i;
        for(int j=0; j<cnt && i*prime[j]<=MAXN; j++)
        {
            vis[i*prime[j]]=i;
            if(i%prime[j]==0)break;
        }
    }
}
ll qpow(ll a,ll b)
{
    ll ans=1,base=a;
    while(b!=0)
    {
        if(b&1!=0)ans*=base;
        base*=base;
        b>>=1;
    }
    return ans;
}
int main()
{
    ll n,p;
    isprime();
    //for(int i=0;i<cnt;i++)printf("%lld ",prime[i]);
    scanf("%lld%lld",&n,&p);
    ll sum=p;
    ll ans=1;
    for(int i=0; i<cnt && prime[i]<=sum; i++)
    {
        int k=0;
        while(sum%prime[i]==0)
        {
            sum/=prime[i];
            k++;
        }
        //printf("%lld\n",sum);
        if(k>=n)ans*=qpow(prime[i],k/n);

    }
    if(n==1 && sum>1)ans*=sum;//多出一个素数来
    printf("%lld\n",ans);

    return 0;
}
