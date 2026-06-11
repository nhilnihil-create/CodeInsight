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
const int N=300+50;
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

int n,f[N<<1][N<<1];
char s[N][N],sq[N<<1][N<<1];

int main()
{
    n=read();
    rep(i,1,n) scanf("%s",s[i]+1);
    rep(i,1,n*2) rep(j,1,n*2)
    {
        int x=i,y=j;
        if (x>n) x-=n;
        if (y>n) y-=n;
        sq[i][j]=s[x][y];
    }
    /*rep(i,1,n*2)
    {
        rep(j,1,n*2) putchar(sq[i][j]);
        puts("");
    }*/
    int ans=0;
    rep(i,1,n*2-1) rep(j,1,n*2-1)
    {
        int cnt=0,k=0;
        while ((k<min(i,j)) && (sq[i][j-k]==sq[i-k][j])) k++;k--;
        //cout << i << " " << j << " " << k << endl;
        f[i][j]=1+min(f[i-1][j-1],k);
        if (f[i][j]>=n) ans++;
    }
    printf("%d\n",ans);
    return 0;
}