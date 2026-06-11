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
const int N=200000+100;
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
void addedge(int u,int v)
{
    all++;sq[all].to=v;sq[all].nxt=head[u];head[u]=all;
}

int n,m,ans,a[N],d[N][2];
queue<int> q;
bool vis[N];
char s[N];

int main()
{
    n=read();m=read();
    scanf("%s",s+1);
    rep(i,1,n) a[i]=(s[i]=='B');
    rep(i,1,m)
    {
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
        d[u][a[v]]++;d[v][a[u]]++;
    }
    rep(i,1,n)
    {
        if ((!d[i][0]) || (!d[i][1]))
        {
            vis[i]=1;q.push(i);
        }
    }
    while (!q.empty())
    {
        int u=q.front();q.pop();
        go(u,i)
        {
            d[v][a[u]]--;
            if (((!d[v][0]) || (!d[v][1])) && (!vis[v])) {q.push(v);vis[v]=1;}
        }
    }
    rep(i,1,n) if (!vis[i]) {puts("Yes");return 0;}
    puts("No");return 0;
}