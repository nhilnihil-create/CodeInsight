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
const int N=200000+100,bas=100001;
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

int n,l[N],r[N];
vi ql[N],qr[N];
bool vis[N];

ll solve(int op)
{
    rep(i,1,bas*2) {ql[i].clear();qr[i].clear();}
    rep(i,1,n)
    {
        vis[i]=0;
        ql[l[i]].pb(i);
        qr[r[i]].pb(i);
    }
    int pl=bas*2,pr=0,pos=bas;ll ans=0;
    while (1)
    {
        if (op)
        {
            while ((pl>pos) && ((ql[pl].empty()) || (vis[ql[pl].back()])))
            {
                if (ql[pl].empty()) pl--;
                else if (vis[ql[pl].back()]) ql[pl].pop_back();
            }
            if (pl<=pos) break;
            ans+=(pl-pos);vis[ql[pl].back()]=1;pos=pl;
        }
        else
        {
            while ((pr<pos) && ((qr[pr].empty()) || (vis[qr[pr].back()])))
            {
                if (qr[pr].empty()) pr++;
                else if (vis[qr[pr].back()]) qr[pr].pop_back();
            }
            if (pr>=pos) break;
            ans+=(pos-pr);vis[qr[pr].back()]=1;pos=pr;
        }
        op^=1;
    }
    ans+=abs(pos-bas);
    return ans;
}       

int main()
{
    n=read();
    rep(i,1,n) {l[i]=read()+bas;r[i]=read()+bas;}
    printf("%lld\n",max(solve(0),solve(1)));
    return 0;
}