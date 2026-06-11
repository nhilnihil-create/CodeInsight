#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 200010
inline ll read()
{
	ll x=0; char c=getchar(),f=1;
	for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
	for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
inline void write(ll x)
{
	static char buf[20];
	int len=0;
	if(x<0)putchar('-'),x=-x;
	for(;x;x/=10)buf[len++]=x%10+'0';
	if(!len)putchar('0');
	else while(len)putchar(buf[--len]);
}
inline void writesp(ll x){write(x); putchar(' ');}
inline void writeln(ll x){write(x); putchar('\n');}
struct edge{
	int to,nxt;
}e[4*maxn];
int fir[4*maxn],in[4*maxn];
int q[4*maxn];
char s[maxn];
int n,m,tot;
inline void add_edge(int x,int y){++in[y]; e[tot].to=y; e[tot].nxt=fir[x]; fir[x]=tot++;}
int main()
{
	n=read(); m=read();
	scanf("%s",s+1);
	memset(fir,255,sizeof(fir));
	memset(in,0,sizeof(in));
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		if(s[x]=='A'&&s[y]=='A')add_edge(x+3*n,y),add_edge(y+3*n,x);
		else if(s[x]=='B'&&s[y]=='B')add_edge(x+n,y+2*n),add_edge(y+n,x+2*n);
		else add_edge(x,y+n),add_edge(y,x+n),add_edge(x+2*n,y+3*n),add_edge(y+2*n,x+3*n);
	}
	int h=1,t=0;
	for(int i=1;i<=4*n;i++)
		if(!in[i])q[++t]=i;
	while(h<=t){
		int now=q[h++];
		for(int i=fir[now];~i;i=e[i].nxt){
			--in[e[i].to];
			if(!in[e[i].to])q[++t]=e[i].to;
		}
	}
	if(t==4*n)puts("No");
	else puts("Yes");
	return 0;
}