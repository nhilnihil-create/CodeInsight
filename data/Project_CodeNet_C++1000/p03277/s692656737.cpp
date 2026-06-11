#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010;
int n,nn,L,R,mid,a[N],b[N],c[N<<1];
int read() {
	int tmp=0, fh=1; char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') fh=-1; c=getchar();}
	while (c>='0'&&c<='9') tmp=tmp*10+c-48, c=getchar();
	return tmp*fh;
}
void add(int x) {
	//printf("add %d\n",x);
	for (;x<=n*2+1;x+=(x&(-x))) c[x]++;
}
long long query(int x) {
	long long y=0;
	//printf("query %d ",x);
	for (;x;x-=(x&(-x))) y+=c[x];
	//printf("%lld\n",y);
	return y;
}
bool ok(int x) {
	int tmp=n+1;
	long long cnt=0;
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++) {
		add(tmp); if (a[i]<=x) tmp--; else tmp++;
		cnt+=i-query(tmp);
	}
	//printf("%d %lld\n",x,cnt);
	if ((cnt-1)*4>1ll*n*(n+1)) return 1;
	return 0;
}
int main() {
	nn=n=read();
	for (int i=1;i<=n;i++) b[i]=a[i]=read();
	sort(b+1,b+n+1); nn=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+nn+1,a[i])-b;
	L=0; R=nn;
	while (L+1<R) {
		mid=(L+R)>>1;
		if (ok(mid)) R=mid; else L=mid;
	}
	printf("%d\n",b[R]);
}