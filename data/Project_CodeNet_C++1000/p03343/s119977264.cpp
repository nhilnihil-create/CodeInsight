#define FILEIO(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
#include <stdio.h>
#include <queue>
#include <algorithm>
#define N 10005
using namespace std;
int n,k,q,a[N],b[N],c[N];
inline void smin(int &a,int b){b<a?a=b:0;}
inline int read() {
	char c=getchar();int x=0;
	while(c<48||c>57) c=getchar();
	while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int solve(int x) {
	int i,j,ans,m,t,p;
	ans=0;m=0;
	for(i=0;i<n;++i) {
		for(j=i;j<n&&a[j]>=x;++j);
		if(j-i>=k) {
			p=j-i-k;
			for(t=0;i<j;) b[t++]=a[i++];
			sort(b,b+t);
			while(~p) c[m++]=b[p--];
		}
	}
	if(m<q) return 1<<30;
	sort(c,c+m);
	return c[q-1]-x;
}
int main() {
//	FILEIO("operation");
	int i,ans=1<<30;
	n=read();k=read();q=read();
	for(i=0;i<n;++i) a[i]=read();
	for(i=0;i<n;++i) smin(ans,solve(a[i]));
	printf("%d",ans);
	return 0;
}