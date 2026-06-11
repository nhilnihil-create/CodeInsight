#include<stdio.h>
long long a[10001],b[10001];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i)
		scanf("%lld",a+i);
	for(int i=0; i<n; ++i)
		scanf("%lld",b+i);
	long long p=0,q=0;
	for(int i=0; i<n; ++i) {
		if(a[i]>b[i]) p+=a[i]-b[i];
		if(a[i]<b[i]) q+=(b[i]-a[i])>>1;
	}
	puts(p<=q?"Yes":"No");
	return 0;
}