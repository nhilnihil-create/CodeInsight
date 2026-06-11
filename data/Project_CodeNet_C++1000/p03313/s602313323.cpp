#include <iostream>
#include <cstdio>
using namespace std;

int n, s1, s2, mx, a[300000];
int main() {
	int i, j;
	cin >> n;
	for(i=0; i<1<<n; i++) scanf("%d", &a[i]);
	for(i=1; i<1<<n; i++) {
		s1=a[0], s2=0;
		for(j=i; j; j=(j-1)&i) {
			if(a[j] > s1) {
				s2 = s1;
				s1 = a[j];
			} else if(a[j] > s2) {
				s2 = a[j];
			}
		}
		mx = max(mx, s1 + s2);
		printf("%d\n", mx);
	}
	return 0;
}