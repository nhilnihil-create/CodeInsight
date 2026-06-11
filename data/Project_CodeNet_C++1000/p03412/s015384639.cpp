#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define eps 1e-18
inline ll read()
{
    ll tmp=0; char c=getchar(),f=1;
    for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
    for(;'0'<=c&&c<='9';c=getchar())tmp=(tmp<<3)+(tmp<<1)+c-'0';
    return tmp*f;
}
using namespace std;
ll a[200010],b[200010];
ll tmp[200010];
int n;
ll find(ll k)
{
    int l=1,r=n+1;
    while(l<r){
        int mid=(l+r)>>1;
        if(tmp[mid]>=k)r=mid;else l=mid+1;
    }
    return l;
}
int main()
{
    int i,k;
    n=read();
    for(i=1;i<=n;i++)a[i]=read();
    for(i=1;i<=n;i++)b[i]=read();
    ll ans=0;
    for(k=1;k<=29;k++){
        ll base=(1<<k)-1;
        for(i=1;i<=n;i++)tmp[i]=b[i]&base;
        sort(tmp+1,tmp+n+1);
        ll cnt=0; 
        for(i=1;i<=n;i++)
            cnt+=n-find((1<<(k-1))-(a[i]&base))+1;
        for(i=1;i<=n;i++)
            cnt-=find((1<<k)+(1<<(k-1))-(a[i]&base))-find((1<<k)-(a[i]&base));
        if(cnt&1)ans+=(1<<(k-1));
    }
    printf("%lld\n",ans);
}