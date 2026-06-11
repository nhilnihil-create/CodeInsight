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

int n,m,f[310][310][310];
char s[310];

int dfs(int l,int r,int k)
{
    if (l==r) return 1;
    if (l>r) return 0;
    if (f[l][r][k]!=-1) return f[l][r][k];
    f[l][r][k]=max(dfs(l,r-1,k),dfs(l+1,r,k));
    if (s[l]==s[r]) f[l][r][k]=max(f[l][r][k],dfs(l+1,r-1,k)+2);
    else if (k) f[l][r][k]=max(f[l][r][k],dfs(l+1,r-1,k-1)+2);
    return f[l][r][k];
}

int main()
{
    memset(f,-1,sizeof(f));
    scanf("%s",s+1);m=read();
    n=strlen(s+1);
    printf("%d",dfs(1,n,m));
    return 0;
}