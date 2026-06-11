#include <iostream>
#include <cstdio>
using namespace std;

int l, n, m;
int main() {
	int i, k;
	cin>>l;
	for(n=1; 1<<n <= l; n++);
	for(i=n-1; i; i--) if(l&1<<i-1) m++;
	printf("%d %d\n", n, 2*n+m-2);
	for(i=1; i<n; i++) {
		printf("%d %d %d\n", i, i+1, 0);
		printf("%d %d %d\n", i, i+1, 1<<i-1);
	}
	for(i=n-1, k=1<<n-1; i; i--) {
		if(l&1<<i-1) printf("%d %d %d\n", i, n, k), k += 1<<i-1;
	}
	return 0;
}