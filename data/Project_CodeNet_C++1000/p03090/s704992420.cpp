#include <cstdio>
#include <algorithm>
int doing(int n) {
	
}
int main() {
	int n;
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			if(j!=n-i+(n+1)%2) {
				++cnt;
			}
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i) {
		for(int j=i+1;j<=n;++j) {
			if(j!=n-i+(n+1)%2) {
				printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
}