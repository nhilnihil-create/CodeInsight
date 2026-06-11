#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
int main() {
	int i;
	cin >> n >> k;
	if(k >= 1<<n) return puts("-1")*0;
	if(n==1) {
		if(k==0) return puts("0 0 1 1")*0;
		else return puts("-1")*0;
	}
	printf("%d ", k);
	for(i=0; i<1<<n; i++) if(i!=k) printf("%d ", i);
	printf("%d ", k);
	for(i=(1<<n)-1; i>=0; i--) if(i!=k) printf("%d ", i);
	return 0;
}