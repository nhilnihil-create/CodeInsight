#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<math.h>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=100000+100;
const db pi=acos(-1.0);
#define lowbit(x) ((x)&(-x))
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define go(u,i) for (register int i=head[u],v=sq[i].to;i;i=sq[i].nxt,v=sq[i].to)
#define fir first
#define sec second
#define mkp make_pair
#define pb push_back
#define maxd 998244353
#define eps 1e-8
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

inline ll readll()
{
    ll x=0;int f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

struct node{int to,nxt;}sq[N<<1];
int all=0,head[N];
ll dis[N];

void addedge(int u,int v)
{
    all++;sq[all].to=v;sq[all].nxt=head[u];head[u]=all;
}

void dfs(int u,int fu)
{
    go(u,i) 
        if (v!=fu) 
        {
            dis[v]=dis[u]+1;
            dfs(v,u);
        }
}

struct pnode{int id;ll dis;}p[N];
bool cmp(pnode p,pnode q) {return p.dis>q.dis;}
int n,siz[N];
map<ll,int> mp;
vector<pii> ans;

int main()
{
    n=read();
    rep(i,1,n)
    {
        p[i].dis=readll();
        p[i].id=i;siz[i]=1;
        mp[p[i].dis]=i;
    }
    sort(p+1,p+1+n,cmp);
    rep(i,1,n-1)
    {
        int u=p[i].id;
        int delta=2*siz[u]-n;
        if (delta>=0) {puts("-1");return 0;}
        ll nxt=p[i].dis+delta;
        if (!mp[nxt]) {puts("-1");return 0;}
        int v=mp[nxt];
        siz[v]+=siz[u];
        addedge(u,v);addedge(v,u);
        ans.pb(mkp(u,v));
    }
    //cout << "from " << p[1].id << endl;
    dfs(p[1].id,0);
    ll sum=0;
    //rep(i,1,n) cout << dis[i] << " ";cout << endl;
    rep(i,1,n) sum+=dis[i];
    if (sum!=p[1].dis) {puts("-1");return 0;}
    rep(i,0,n-2) printf("%d %d\n",ans[i].fir,ans[i].sec);
    return 0;
}
