#include <stdio.h>
#include <algorithm>
const int N=18;
const int M=(1<<N)+5;
int n,m,x[M],f[M],g[M],t[4];
inline void smax(int &a,int b){b>a?a=b:0;}
inline bool cmp(int a,int b) {
	return x[a]>x[b];
}
int main() {
	int i,j,ans=0;
	scanf("%d",&n);m=1<<n;
	for(i=0;i<m;++i) scanf("%d",x+i);
	f[0]=0;g[0]=m;x[m]=-1;
	for(i=1;i<m;++i) {
		t[0]=i;t[1]=m;
		for(j=1;j<=i;j<<=1) if(i&j) {
			t[2]=f[i^j];t[3]=g[i^j];
			std::sort(t,t+4,cmp);
			std::unique(t,t+4);
		}
		f[i]=t[0];g[i]=t[1];
		smax(ans,x[f[i]]+x[g[i]]);
		printf("%d\n",ans);
	}
	return 0;
}