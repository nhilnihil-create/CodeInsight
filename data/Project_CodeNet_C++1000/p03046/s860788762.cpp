#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	if(m>=(1<<n)) {
		puts("-1");
		return 0;
	}
	if(n==1) {
		if(m) {
			puts("-1");
		} else {
			puts("1 1 0 0");
		}
		return 0;
	}
	for(register int i=0; i<(1<<n); i++) {
		if(i!=m) {
			printf("%d ",i);
		}
	}
	printf("%d ",m);
	for(register int i=(1<<n)-1; i>=0; i--) {
		if(i!=m) {
			printf("%d ",i);
		}
	}
	printf("%d ",m);
	return 0;
}