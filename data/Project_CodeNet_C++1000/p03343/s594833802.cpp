#define FILEIO(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
#include <stdio.h>
#include <queue>
#include <algorithm>
#define N 10005
using namespace std;
int n,k,q,a[N],b[N],c[N];
inline int min(int a,int b){return a<b?a:b;}
int solve(int x) {
	int i,j,ans=0,m=0,t,p;
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
	scanf("%d%d%d",&n,&k,&q);
	for(i=0;i<n;++i) scanf("%d",a+i);
	for(i=0;i<n;++i) ans=min(ans,solve(a[i]));
	printf("%d",ans);
	return 0;
}