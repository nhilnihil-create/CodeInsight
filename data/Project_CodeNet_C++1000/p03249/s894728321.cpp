#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<bitset>
#define Fail puts("NO"),exit(0);
#define eps 1e-10
#define maxn 100010
#define maxm 100010
#define inf 1000000007
//#define mod 1000000009
#define inv 500000005
#define G 3
#define pi acos(-1)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll,int>pii;
typedef bitset<maxn> bit;
typedef long double ld;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,siz[maxn];
pii p[maxn];
int head[maxn],nxt[maxn*2],to[maxn*2],tot;
void add(int u,int v)
{
    tot++;
    nxt[tot]=head[u];
    head[u]=tot;
    to[tot]=v;
}
int u[maxn],v[maxn];
ll dfs(int x,int las,ll d)
{
    ll res=d;
    for(int i=head[x];i;i=nxt[i])
      if(to[i]!=las)  res+=dfs(to[i],x,d+1);
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)  p[i].fi=read(),p[i].se=i,siz[i]=1;
    sort(p+1,p+n+1);reverse(p+1,p+n+1);
    for(int i=1;i<n;i++)
    {
        int l=1,r=n,pos=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(p[mid].fi>=p[i].fi+2*siz[i]-n)
            {
                pos=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        if(p[pos].fi!=p[i].fi+2*siz[i]-n)  return puts("-1"),0;
        siz[pos]+=siz[i];
        u[i]=p[pos].se;v[i]=p[i].se;
        add(u[i],v[i]);
        add(v[i],u[i]);
    }
    ll com=dfs(p[n].se,0,0);
    if(com!=p[n].fi)   return puts("-1"),0;
    for(int i=1;i<n;i++)  printf("%d %d\n",u[i],v[i]);
    return 0;
}