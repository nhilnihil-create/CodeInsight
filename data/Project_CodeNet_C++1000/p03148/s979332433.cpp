#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
inline int read() 
{
    register int x = 0 , ch = getchar(); 
    while( !isdigit( ch ) ) ch = getchar(); 
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();     
    return x; 
}
ll quick_power(ll a,ll b,ll modn)
{
    ll ans=1;
    while(b)
    {
        if(b%2)
            ans=ans*a%modn;
        a=a*a%modn;
        b=(b>>1);
    }
}
ll turtle_muti(ll ain,ll bin,ll modn)
{
    ll res=0;
    for(;bin;bin>>=1) 
    {
        if(bin&1)
            res=(res+ain)%modn;
        ain=(ain<<1)%modn;
    }
    return res;
}
/*------------------Coding Area------------------*/
const int maxn=1000010;
const int inf=0x3f3f3f3f;
int n,k;
struct info
{
    int x,v;
}a[maxn];
bool cmp(info one,info two)
{
    return one.v>two.v;
}
int vis[maxn];
stack<int> s;
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d %d",&a[i].x,&a[i].v);
    sort(a+1,a+1+n,cmp);
    ll cnt=0;
    ll tp=0;
    ll res=0;
    ll ans=0ll;
    for(int i=1;i<=n;++i)
    {
        if(cnt<k)
        {
                if(vis[a[i].x]==0)
                {
                    vis[a[i].x]=1;
                    tp++;
                }
                else
                    s.push(a[i].v);
                res+=a[i].v;
                cnt++;
                ans=max(ans,res+1ll*tp*tp);
        }
        else
        {
            if(s.empty())
                break;
            if(vis[a[i].x])
                continue;
            vis[a[i].x]=1;
            tp++;
            res-=s.top();
            res+=a[i].v;
            s.pop();
            ans=max(ans,res+tp*tp);
        }
    }
    printf("%lld\n",ans);
    return 0;
}