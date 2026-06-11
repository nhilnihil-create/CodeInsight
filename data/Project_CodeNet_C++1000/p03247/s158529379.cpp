#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N=1010,M=1000010,P=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=0xcfcfcfcf;
const db eps=1e-9,pi=asin(1)*2;
inline ll read();
#define cmax(a,b) a=max(a,b)
#define cmin(a,b) a=min(a,b)
inline int ADD(int a,int b) { return a+b>=P?a+b-P:a+b; }
inline int MINUS(int a,int b) { return a-b<0?a-b+P:a-b; }
#define plus(a,b) a=ADD(a,b)
#define minus(a,b) a=MINUS(a,b)
#define mul(a,b) a=(1ll*a*(b))%P
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp(x,y) make_pair(x,y)

int n,m;
ll x[N],y[N];
ll d[N];
char s[N];
const char ch[]={'U','R','D','L'};

inline int work(ll &x,ll d)
{
	if(x>=0)
	{
		x-=d;
		return 0;
	}
	else
	{
		x+=d;
		return 2;
	}
}

#ifdef FILE
const int RS=1<<20;
char buf[RS],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,RS,stdin),p1==p2)?EOF:*p1++
#endif
inline ll read()
{
	ll s=0;
	bool flag=false;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') flag=true;
	for(;'0'<=ch&&ch<='9';ch=getchar()) s=(s<<3)+(s<<1)+(ch^'0');
	if(flag) return -s;
	return s;
}

int main()
{
#ifdef FILE
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
#endif
	n=read(),m=32;
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for(int i=1;i<=m;i++) d[i]=1ll<<m-i;
	for(int i=1;i<n;i++)
	{
		if((x[i]+y[i]&1)!=(x[i+1]+y[i+1]&1))
		{
			printf("-1\n");
			return 0;
		}
	}
	if(x[1]+y[1]&1^1) d[++m]=1;
	printf("%d\n",m);
	for(int i=1;i<=m;i++) printf("%lld ",d[i]);
	putchar('\n');
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(abs(x[i])>abs(y[i])) s[j]=ch[work(x[i],d[j])+1];
			else s[j]=ch[work(y[i],d[j])];
		}
//		reverse(s+1,s+m+1);
		printf("%s\n",s+1);
	}
	return 0;
}