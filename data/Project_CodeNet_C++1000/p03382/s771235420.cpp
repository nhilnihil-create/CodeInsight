#include <bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n, a[100010];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	sort(a+1, a+n+1);
	int mn = 2e9, idx = 0;
	for(int i=1; i<n; i++) {
		if(a[n] % 2) {
			int v = min(abs(a[n] / 2 - a[i]), abs(a[n] / 2 + 1 - a[i]));
			if(v < mn) mn = v, idx = i;
		} else {
			int v = abs(a[n] / 2 - a[i]);
			if(v < mn) mn = v, idx = i;
		}
	}
	printf("%d %d", a[n], a[idx]);
	return 0;
}