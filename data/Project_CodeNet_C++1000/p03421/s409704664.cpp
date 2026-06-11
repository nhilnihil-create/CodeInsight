#include <bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n, a, b;
int main() {
	scanf("%d%d%d", &n, &a, &b);
	if(n < a + b - 1 || n > 1ll * a * b) { puts("-1"); return 0; }
	if(a == 1) {
		for(int i=n; i>=1; i--) printf("%d ", i);
		return 0;
	}
	if(b == 1) {
		for(int i=1; i<=n; i++) printf("%d ", i);
		return 0;
	}
	for(int i=b; i>=1; i--) printf("%d ", i);
	int curr = b + 1;
	for(int i=0; i<a-1; i++) {
		int len = ((n - curr + 1) + a - i - 2) / (a - i - 1);
		for(int j=curr+len-1; j>=curr; j--) printf("%d ", j);
		curr += len;
	}
	return 0;
}