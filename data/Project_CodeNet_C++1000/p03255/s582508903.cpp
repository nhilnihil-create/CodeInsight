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

int n,x;
ll a[N],s[N];

int main()
{
    n=read();x=read();
    rep(i,1,n) s[i]=s[i-1]+read();
    a[1]=5;
    rep(i,2,n) a[i]=i*2+1;
    db ans=1e100;
    rep(k,1,n)
    {
        db now=0;int j=1;
        //cout << "now " << k << endl;
        rep(i,1,(n-1)/k+1)
        {
            int r=n-(i-1)*k,l=r-k+1;l=max(1,l);
            //cout << l << " " << r << " " << j << endl;
            now+=a[i]*(s[r]-s[l-1]);j++;
        }
        now+=1ll*x*(n+k);
        ans=min(now,ans);
    }
    printf("%lld\n",(ll)ans);
    return 0;
}
