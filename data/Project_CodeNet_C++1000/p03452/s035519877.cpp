#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define drp(i,st,ed) for (int i=st;i>=ed;--i)

const int N=1011111;

int fa[N],d[N];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

int find(int x) {
	if (!fa[x]) return x;
	int f=find(fa[x]);
	d[x]+=d[fa[x]];
	return fa[x]=f;
}

int main(void) {
	int n=read(),m=read();
	for (;m--;) {
		int x=read(),y=read(),k=read();
		int fx=find(x),fy=find(y);
		if (fx==fy) {
			if (d[y]-d[x]!=k) return 0&puts("No");
		} else fa[fy]=fx,d[fy]=d[x]+k-d[y];
	}
	return 0&puts("Yes");
}