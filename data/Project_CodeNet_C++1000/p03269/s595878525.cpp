#include <stdio.h>
int n,m=0,p=0,a[50],b[50],c[50];
int main() {
	scanf("%d",&n);
	while(n>1) {
		++m;
		if(n&1) b[p]=m,c[p]=n-1,++p;
		a[m]=n>>=1;
	}
	printf("%d %d\n",m+1,m*2+p);
	for(int i=1;i<=m;++i) printf("%d %d %d\n%d %d %d\n",i,i+1,a[i],i,i+1,0);
	for(int i=0;i<p;++i) printf("%d %d %d\n",b[i],m+1,c[i]);
	return 0;
}