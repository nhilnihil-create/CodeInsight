#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int n,l,r,mid,j,p[N],siz[N],fa[N];
long long d[N],dis[N];
bool cmp(int x,int y) {return d[x]<d[y];}
long long read() {
	long long tmp=0, fh=1; char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
	while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
	return tmp*fh;
}
int main() {
	n=read();
	for (int i=1;i<=n;i++) d[i]=read(), p[i]=i, siz[i]=1;
	sort(p+1,p+n+1,cmp);
	for (int i=n,j=i-1;i>1;i--) {
		l=1; r=i;
		while (l+1<r) {
			mid=(l+r)>>1;
			if (d[p[mid]]<=d[p[i]]+siz[p[i]]*2-n) l=mid; else r=mid;
		}
		j=l;
		if (d[p[j]]==d[p[i]]+siz[p[i]]*2-n) siz[p[j]]+=siz[p[i]], dis[p[j]]+=dis[p[i]]+siz[p[i]], fa[p[i]]=p[j];
		else {
			printf("-1\n"); return 0;
		}
	}
	if (dis[p[1]]!=d[p[1]]) printf("-1\n"); else
		for (int i=2;i<=n;i++) printf("%d %d\n",fa[p[i]],p[i]);
	return 0;
} 