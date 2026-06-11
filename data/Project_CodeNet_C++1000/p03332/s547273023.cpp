/*
精灵引路
对应原理
尽量往后排 同样
*/
#include<bits/stdc++.h>
#define MAXN 3000005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef long long ll;
const ll INF=1e18;
const ll MOD=998244353;
const ll mod=998244353;
//wa说明精度太大了 把精度减小 变成3e-7
const double eps=1e-6;
ll n,a,b,k,inv[MAXN],c[MAXN],ans;
ll add(ll x,ll y)
{
    ll ret=x+y;
    if(ret>=mod)
    {
        return ret-mod;
    }
    return ret;
}
ll mul(ll x,ll y)
{
    return (x*y)%mod;
}
void init()
{
    inv[1]=1;
    for(ll i=2;i<=n;i++)
    {
        ll a=MOD/i,b=MOD%i;
        inv[i]=(inv[b]*(-a)%MOD+MOD)%MOD;
    }
    c[0]=1;
    for(ll i=1;i<=n;i++)
    {
        c[i]=mul(mul(c[i-1],(n-i+1)),inv[i]);
    }
}
int main()
{
//    freopen("c://duipai//939cdata.txt", "r", stdin);
//    freopen("c://duipai//939cac.txt", "w", stdout);
    while(~scanf("%lld %lld %lld %lld",&n,&a,&b,&k))
    {
        init();
        for(ll i=0;i<=n;i++)
        {
            ll s1=a*i;
            ll s2=k-s1;
            ll n2;
            if(s2%b)
            {
                continue;
            }
            else
            {
                n2=s2/b;
            }
            if(n2>=0)
            {
                ans=add(ans,mul(c[i],c[n2]));
            }
           // printf("%lld %lld\n",i,n2);

        }
        printf("%lld\n",ans);
    }
}
/*
1
2 3
  +---+       +---+
 /     \     /     \
+       +---+   T   +
 \           \     /
  +   +       +---+
 /     \     /     \
+       +---+       +
 \                 /
  +---+   S   +---+
       \     /
        +---+
*/
