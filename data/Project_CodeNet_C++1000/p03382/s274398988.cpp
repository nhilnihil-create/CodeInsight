#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxN = 1e5 + 5;
int a[maxN], N;
int myabs(int val) {
	return (val < 0) ? -val : val;
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + N);
	int val = a[1], mid = (a[N] + 1) / 2;
	for(int i = 2; i < N; ++i) 
		if(abs(mid - val) > abs(mid - a[i])) val = a[i];
	printf("%d %d\n", a[N], val);
	return 0;
}