#include "bits/stdc++.h"
using namespace std;
int n, k, q;
int a[2005];
int b[2005];

bool good(int x, int y) {
	int l = 0;
	int ans = 0;
	while(l < n) {
		int r = l;
		int cnt = 0;
		while(r < n && a[r] >= x) {
			cnt += (a[r] <= y);
			++r;
		}
		ans += max(0, min(r - l - k + 1, cnt));
		l = r + 1;
	}
	return ans >= q;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &n, &k, &q);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i]; 
	}
	sort(b, b + n);
	int ans = b[n - 1] - b[0];
	for(int i = 0; i < n; i++) {
		int l = i, r = n - 1;
		while(l < r) {
			int m = (l + r) >> 1;
			if(good(b[i], b[m])) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		if(good(b[i], b[l])) {
			ans = min(ans, b[l] - b[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}