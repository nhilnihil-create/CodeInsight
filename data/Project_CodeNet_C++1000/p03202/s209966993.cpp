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

int n,a[N],pos[N],num[N];

int chk(int mid)
{
    if (mid==1)
    {
        rep(i,2,n) if (a[i]<=a[i-1]) return 0;
        return 1;
    }
    int tp=0;
    rep(i,2,n)
    {
        if (a[i]>a[i-1]) continue;
        while ((tp) && (pos[tp]>a[i])) tp--;
        int nowp=a[i];
        while ((tp) && (pos[tp]==nowp) && (num[tp]==mid)) {nowp--;tp--;}
        if (!nowp) return 0;
        if (pos[tp]==nowp) num[tp]++;
        else {pos[++tp]=nowp;num[tp]=2;}
    }
    return 1;
}


int main()
{
    n=read();
    rep(i,1,n) a[i]=read();
    int ans=0,l=1,r=1e9;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (chk(mid)) {ans=mid;r=mid-1;}
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}