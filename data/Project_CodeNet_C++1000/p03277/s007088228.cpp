#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
const int maxn=1e5+7;
const ll modn=1e9+7;
const int inf=2e9+7;
const ll INF=1000000000000000000ll;
const double PI = acos(-1.0);
const double eps=1e-8;
inline int lowbit(int x){return x&-x;}
inline ll lowbit(ll x) {return x&-x;}
inline int CountOneBinary(ll num){int ans=0;while(num){if(num&1) ans+=1;num>>=1;}return ans;}
inline void read(int &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline void read(ll &x){char c;x=0;for(c=getchar();c>'9'||c<'0';c=getchar());for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';}
inline ll qpow(ll x,ll y){ll ans=1;while(y){if(y&1) ans=ans*x%modn;x=x*x%modn;y>>=1;}return ans;}
inline double qpow(double x,ll y){double ans=1;while(y){if(y&1) ans=ans*x;x=x*x;y>>=1;}return ans;}
ll n,a[maxn],C[maxn],sum[maxn],stn;
void add(int pos)
{
    for(int i=pos;i<maxn;i+=lowbit(i)) C[i]++;
}
ll query(int pos)
{
    ll ans=0;
    for(int i=pos;i;i-=lowbit(i)) ans+=C[i];
    return ans;
}
bool check(ll x)
{
    memset(C,0,sizeof(C));
    ll bot=1;
    for(int i=1;i<=n;i++)
    {
        if(x<=a[i]) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
        bot=min(sum[i],bot);
    }
    bot-=2;
    ll ans=0;
    add(-bot);
    for(int i=1;i<=n;i++)
    {
        sum[i]-=bot;
        ans+=query(sum[i]);
        add(sum[i]);
    }
    return ans>=stn;
}
int main()
{
    while(scanf("%lld",&n)==1)
    {
        stn=n*(n+1)/2-n*(n+1)/2/2;
        ll l=1e9,r=1;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),l=min(a[i],l),r=max(a[i],r);
        while(l<r)
        {
            ll mid=l+(r-l+1)/2;
            if(check(mid))
                l=mid;
            else
                r=mid-1;
        }
        printf("%lld\n",l);
    }
}
