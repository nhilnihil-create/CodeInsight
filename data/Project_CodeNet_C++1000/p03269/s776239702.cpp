#include<bits/stdc++.h>
using namespace std;
const int N = 25;

int l, n = 1, m, a[N];
bool b[N];

int main() {
	scanf("%d",&l);
	l--;
	for(int i=1;;i++) {
		if(!l) break;
		n++;
		a[i] = l/2+1;
		b[i] = (l%2);
		m += 2 + !b[i];
		l = (l-1)/2;
	}
	printf("%d %d\n", n, m);
	for(int i=1;i<n;i++) {
		printf("%d %d %d\n", i, i+1, a[i]);
		if(b[i]) {
			printf("%d %d 0\n", i, i+1);
		}
		else {
			printf("%d %d 1\n", i, i+1);
			printf("%d %d 0\n", i, n);
		}
	}
}
