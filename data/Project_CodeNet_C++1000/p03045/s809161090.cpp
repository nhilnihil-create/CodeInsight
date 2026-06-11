#include<cstdio>
int n,m,ans,is;
int prt[100001];
int belong[100001],cnt;
inline int read() {
	int ln=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		ln=ln*10+ch-'0';
		ch=getchar();
	}
	return ln;
}
inline int find(int x) {
	if(prt[x]==x) return x;
	return prt[x]=find(prt[x]);
}
inline void init() {
	n=read(),m=read();
	for(int i=1;i<=n;i++) prt[i]=i;
	for(int i=1,u,v,w;i<=m;i++) {
		u=read(),v=read(),w=read();
		u=find(u);
		v=find(v);
		if(u!=v) prt[u]=v;
	}
}
inline int find2(int x) {
	if(belong[x]) {
		is=1;
		return belong[x];
	}
	if(prt[x]==x) {
		belong[x]=++cnt;
		return cnt;
	}
	return belong[x]=find2(prt[x]);
}
inline void solve() {
	for(int i=1;i<=n;i++) {
		if(belong[i]==0) {
			is=0;
			find2(i);
			if(is==0) ans++;
		}
	}
	printf("%d",ans);
}
int main() {
	init();
	solve();
	return 0;
}