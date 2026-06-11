#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
const int
	MAX = 1e5 + 5,
	C = 1e5;
int n, a[MAX], freq[2 * MAX];

int64 f(int x) {
	for(int i = 0; i < 2 * MAX; i++)
		freq[i] = 0;

	int64 ans = 0, tot = 0;
	int s = 0;

	freq[C] = 1;
	
	for(int i = 1; i <= n; i++) {
		int v = (a[i] <= x) ? 1 : -1;

		s += v;

		if(v == -1)
			ans -= freq[s + C];

		else ans += freq[s - 1 + C];

		freq[s + C]++;
		tot += ans;
	}

	return tot;
}

int main() {
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int64 M = f(1e9);

	int st = 1, nd = 1e9, ans = 1e9;

	while(st <= nd) {
		int mid = (st + nd) >> 1;

		if(f(mid) >= M / 2 + 1) {
			ans = min(ans, mid);
			nd = mid - 1;
		}

		else st = mid + 1;
	}

	printf("%d\n", ans);
	return 0;
}