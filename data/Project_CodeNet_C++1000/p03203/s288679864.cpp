#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
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
std::vector<int>a[maxn];
int h[maxn];
int n,m,k;
int check(int x,int y)
{
	if(x<1||x>n||y<1||y>m)return 1;
	int pos=std::lower_bound(a[y].begin(),a[y].end(),x)-a[y].begin();
	if(pos==a[y].size())return 0;
	else return (x==a[y][pos]);
}
int main()
{
	n=read(); m=read(); k=read();
	for(int i=1;i<=k;i++){
		int x=read(),y=read();
		a[y].push_back(x);
	}
	for(int i=1;i<=m;i++){
		std::sort(a[i].begin(),a[i].end());
		h[i]=n;
	}
	int x=1,y=1;
	for(int i=1;i<=m;i++){
		// printf("%d %d\n",x,y);
		h[y]=x;
		if(check(x+1,y))break;
		else ++x;
		// puts("A");
		while(x<=n&&check(x,y+1))++x;
		++y;
		if(check(x,y))break;
	}
	int ans=n;
	for(int i=1;i<=m;i++)
		for(int j=0;j<a[i].size();j++)
			if(a[i][j]>h[i])ans=std::min(ans,a[i][j]-1);
	writeln(ans);
	// for(int i=1;i<=m;i++)
	// 	writesp(h[i]);
	// putchar('\n');
	return 0;
}