#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
int main() {
	int i, j;
	cin >> n;
	cout << (n&1 ? (n-1)*(n-1) : n*(n-2)) / 2 << endl;
	k = n + (n%2==0);
	for(i=1; i<=n; i++) for(j=i+1; j<=n; j++) {
		if(i+j!=k) printf("%d %d\n", i, j);
	}
	return 0;
}