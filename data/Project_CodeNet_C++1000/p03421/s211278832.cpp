#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;
int n, A, B, tot;
int main() {
	scanf("%d%d%d", &n, &A, &B);
	if (A + B > n + 1 || 1LL * A * B < n) return puts("-1"), 0;
	n -= A; 
	rep (i, 1, A) {
		tot += min(n, B-1) + 1;
		rep (j, 0, min(n, B-1))
			printf("%d ", tot - j);
		n -= min(n, B-1);
	}
	return 0;
}